#include <bits/stdc++.h>

using namespace std;

struct Point
{
    double x, y;
};

double distance(const Point &p1, const Point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double stripClosest(vector<Point> &strip, double d)
{
    double min_dist = d;
    sort(strip.begin(), strip.end(), [](const Point &p1, const Point &p2)
         { return p1.y < p2.y; });

    for (size_t i = 0; i < strip.size(); ++i)
    {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min_dist; ++j)
        {
            min_dist = min(min_dist, distance(strip[i], strip[j]));
        }
    }
    return min_dist;
}

double closestPairRec(vector<Point> &points, int left, int right)
{
    if (right - left <= 3)
    {
        double min_dist = numeric_limits<double>::infinity();
        for (int i = left; i < right; ++i)
        {
            for (int j = i + 1; j < right; ++j)
            {
                min_dist = min(min_dist, distance(points[i], points[j]));
            }
        }
        return min_dist;
    }

    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];

    double dl = closestPairRec(points, left, mid);
    double dr = closestPairRec(points, mid, right);

    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i < right; ++i)
    {
        if (abs(points[i].x - midPoint.x) < d)
        {
            strip.push_back(points[i]);
        }
    }

    return min(d, stripClosest(strip, d));
}

double closestPair(vector<Point> &points)
{
    sort(points.begin(), points.end(), [](const Point &p1, const Point &p2)
         { return p1.x < p2.x; });
    return closestPairRec(points, 0, points.size());
}

int main()
{
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    double result = closestPair(points);
    cout << fixed << setprecision(3) << result << endl;

    return 0;
}

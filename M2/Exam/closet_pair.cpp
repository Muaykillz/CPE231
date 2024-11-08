#include <bits/stdc++.h>

using namespace std;

int closetPair(vector<int> P, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        cout << P[i] << " ";
    }
    cout << endl;

    if (l >= r)
    {
        return INT_MAX; // ใช้ INT_MAX แทน INFINITY
    }
    else if (r - l == 1)
    {
        return P[r] - P[l];
    }
    else
    {
        int mid = l + (r - l) / 2; // คำนวณ mid อย่างถูกต้อง
        int leftMin = closetPair(P, l, mid);
        int rightMin = closetPair(P, mid + 1, r);
        int crossMin = P[mid + 1] - P[mid];

        int result = min({leftMin, rightMin, crossMin});
        cout << result << endl;
        return result;
    }
}

int main()
{
    vector<int> P = {0, 5, 7, 19, 20, 32, 36, 44};

    int minDis = closetPair(P, 0, P.size() - 1); // แก้ไขขอบเขตให้ถูกต้อง

    cout << minDis << endl;

    return 0;
}

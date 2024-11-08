#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> l(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> l[i];
    }

    int max_current = l[0];
    int max_global = l[0];

    for (int i = 1; i < n; ++i)
    {
        max_current = max(l[i], max_current + l[i]);
        if (max_current > max_global)
        {
            max_global = max_current;
        }
    }

    cout << max_global << endl;

    return 0;
}
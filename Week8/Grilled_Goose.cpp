#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    vector<int> boxSizes(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> boxSizes[i];
    }

    vector<bool> canOrder(x + 1, false);
    canOrder[0] = true;

    for (int i = 0; i < n; ++i)
    {
        for (int j = boxSizes[i]; j <= x; ++j)
        {
            if (canOrder[j - boxSizes[i]])
            {
                canOrder[j] = true;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= x; ++i)
    {
        if (!canOrder[i])
        {
            result = i;
        }
    }

    cout << result << endl;
    return 0;
}
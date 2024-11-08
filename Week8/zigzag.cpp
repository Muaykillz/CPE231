#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> sq(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sq[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, 1));

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sq[i] > sq[j])
            {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            else if (sq[i] < sq[j])
            {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp[i][0] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << dp[i][1] << " ";
    }
    cout << endl;

    return 0;
}
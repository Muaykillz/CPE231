#include <bits/stdc++.h>

using namespace std;

vector<int> Weights;
vector<int> Values;
vector<vector<int>> F;

int MFKnapsack(int i, int j)
{
    if (F[i][j] < 0)
    {
        int value;
        if (j < Weights[i])
        {
            value = MFKnapsack(i - 1, j);
        }
        else
        {
            value = max(MFKnapsack(i - 1, j), Values[i] + MFKnapsack(i - 1, j - Weights[i]));
        }
        F[i][j] = value;
    }
    return F[i][j];
}

int main()
{
    int n, W;
    cin >> n;

    Weights.resize(n + 1);
    Values.resize(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> Weights[i];
        cin >> Values[i];
    }

    cin >> W;

    F.resize(n + 1, vector<int>(W + 1, -1));

    // Initialize row 0 and column 0 with 0s
    for (int i = 0; i <= n; ++i)
    {
        F[i][0] = 0;
    }
    for (int j = 0; j <= W; ++j)
    {
        F[0][j] = 0;
    }

    int maxValue = MFKnapsack(n, W);
    cout << maxValue;

    return 0;
}

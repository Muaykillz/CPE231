#include <bits/stdc++.h>

using namespace std;

// Main
int main()
{
    vector<int> P;
    for (int i = 0; i < 4; i++)
    {
        int p;
        cin >> p;
        P.push_back(p);
    }
    int n;
    cin >> n;
    vector<bool> Flags(n + 1, false);
    Flags[0] = true;

    for (int p : P)
    {
        for (int i = p; i <= n; i++)
        {
            Flags[i] = Flags[i] || Flags[i - p];
        }
    }

    for (int j = n; j >= 0; j--)
    {
        if (!Flags[j])
        {
            cout << j << endl;
            break;
        }
    }

    return 0;
}
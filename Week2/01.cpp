#include <bits/stdc++.h>

using namespace std;

// Factorial
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

// Main
int main()
{
    int n, v;
    cin >> n >> v;
    vector<int> ID[n];
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        ID[i].push_back(id);
    }
    int p;
    cin >> p;

    vector<int> XID[p];
    for (int j = 0; j < p; j++)
    {
        int xid;
        cin >> xid;
        XID[j].push_back(xid);
    }

    cout << factorial(n - 1) * (n - p) << endl;

    return 0;
}
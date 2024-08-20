#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    char A, B;
    cin >> A >> B;

    int length;
    cin >> length;

    int n = s.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == A)
        {
            for (int j = i; j < n; j++)
            {
                if (s[j] == B && j - i + 1 >= length)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
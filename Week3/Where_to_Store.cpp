#include <bits/stdc++.h>

using namespace std;

int main()
{

    string str;
    cin >> str;

    int palindromes = 0;

    for (int i = 0; i < str.size(); i++)
    {
        for (int j = str.size() - 1; j > i; j--)
        {
            if (str[i] == str[j])
            {
                palindromes += j - i;
            }
        }
    }

    cout << palindromes << endl;

    return 0;
}
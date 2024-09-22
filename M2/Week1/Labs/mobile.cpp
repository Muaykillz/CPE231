#include "bits/stdc++.h"

using namespace std;

string genInitialPassword(int n)
{
    string password = "";
    for (int i = 0; i < n; i++)
    {
        password += (char)(i + 'A');
    }
    return password;
}

bool is_concecutive_increasing(string password)
{
    for (int i = 0; i < password.size() - 1; i++)
    {
        if (password[i] < password[i + 1])
        {
            return true;
        }
    }
    return false;
}

vector<string> genAllPossiblePasswords(string init_password)
{
    vector<string> all_possible_passwords;
    all_possible_passwords.push_back(init_password);
    int n = init_password.size();
    while (is_concecutive_increasing(init_password))
    {
        int i, j;
        for (i = n - 2; i >= 0; i--)
        {
            if (init_password[i] < init_password[i + 1])
            {
                break;
            }
        }

        for (j = n - 1; j >= 0; j--)
        {
            if (init_password[j] > init_password[i])
            {
                break;
            }
        }

        swap(init_password[i], init_password[j]);
        reverse(init_password.begin() + i + 1, init_password.end());
        all_possible_passwords.push_back(init_password);
    }
    return all_possible_passwords;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<string> password;

    // input
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (s.size() != n)
        {
            cout << "The password must have " << n << " characters" << endl;
            return 0;
        }
        password.push_back(s);
    }
    string init_password = genInitialPassword(n);

    // process the correct password permutation count
    for (auto &s : password)
    {
        vector<string> all_possible_passwords = genAllPossiblePasswords(init_password);

        int count = 0;
        for (auto &p : all_possible_passwords)
        {
            count++;
            if (p == s)
            {
                break;
            }
        }
        cout << count << endl;
    }

    return 0;
}

// String Matching with Horsepool Algorithm
#include <bits/stdc++.h>

using namespace std;

vector<int> ShiftTable(string pattern)
{
    vector<int> table(256, pattern.length());
    for (int i = 0; i < pattern.length() - 1; i++)
    {
        table[pattern[i]] = pattern.length() - 1 - i;
    }
    return table;
}

pair<int, int> Horsepool(string lottery, string pattern)
{
    vector<int> T = ShiftTable(pattern);
    int i = pattern.length() - 1;
    int shift_count = 0;
    while (i < lottery.length())
    {
        int k = 0;
        while (k < pattern.length() && pattern[pattern.length() - 1 - k] == lottery[i - k])
        {
            k++;
        }
        if (k == pattern.length())
        {
            return {i - pattern.length() + 1, shift_count};
        }
        else
        {
            i += T[lottery[i]];
        }

        shift_count++;
    }
    return {-1, shift_count};
}

int main()
{

    int n, m;
    string lottery, pattern;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        lottery += c;
    }
    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        pattern += c;
    }

    int index, shift_count;
    tie(index, shift_count) = Horsepool(lottery, pattern);

    string result = index == -1 ? "NO " : "YES ";
    cout << result << shift_count << " " << index << endl;

    return 0;
}

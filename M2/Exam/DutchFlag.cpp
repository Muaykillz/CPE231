#include <bits/stdc++.h>

using namespace std;

int main()
{

    string text = "RWBRWB";
    int n = text.size();

    int r = 0, w = 0, b = n - 1;

    while (w <= b)
    {
        if (text[w] == 'R')
        {
            swap(text[w], text[r]);
            r++;
            w++;
        }
        else if (text[w] == 'W')
        {
            w++;
        }
        else
        {
            swap(text[w], text[b]);
            b--;
        }
    }

    cout << text;

    return 0;
}
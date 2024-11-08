#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = arr.size();

    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (arr[i] < 0)
        {
            i++;
        }
        else
        {
            swap(arr[i], arr[j]);
            j--;
        }
    }

    for (auto e : arr)
    {
        cout << e << " ";
    }
    cout << endl;
}
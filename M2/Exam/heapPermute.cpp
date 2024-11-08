#include <bits/stdc++.h>

using namespace std;

void heapPermute(vector<int> &arr, int n)
{
    cout << "heap n: " << n << endl;

    if (n == 1)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        heapPermute(arr, n - 1);
        if (n % 2 == 1)
        {
            swap(arr[0], arr[n - 1]);

            cout << "pre swap x: " << endl;
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            swap(arr[i], arr[n - 1]);

            cout << "pre swap y: " << endl;
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    heapPermute(arr, arr.size());
    return 0;
}
#include "bits/stdc++.h"

using namespace std;

void reverse_vec(vector<int> &A, int i, int j)
{
    while (i < j)
    {
        swap(A[i], A[j]);
        i++;
        j--;
    }
}

vector<int> pancakeSort(vector<int> &A)
{
    for (int i = A.size() - 1; i >= 0; i--)
    {
        int maxIndex = 0;
        for (int j = 0; j <= i; j++)
        {
            if (A[j] > A[maxIndex])
            {
                maxIndex = j;
            }
        }

        reverse_vec(A, 0, maxIndex);
        reverse_vec(A, 0, i);
    }

    return A;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<int> result = pancakeSort(A);

    for (int a : result)
    {
        cout << a << " ";
    }

    return 0;
}
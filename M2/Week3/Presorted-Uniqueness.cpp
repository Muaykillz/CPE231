#include "bits/stdc++.h"

using namespace std;

// =============== QUICK SORT =============== //
int HoarePartition(vector<int> &A, int l, int r)
{
    int p = A[l];
    int i = l;
    int j = r + 1;

    while (i < j)
    {
        do
        {
            i++;
        } while (A[i] < p);

        do
        {
            j--;
        } while (A[j] > p);

        swap(A[i], A[j]);
    }

    swap(A[i], A[j]);
    swap(A[l], A[j]);
    return j;
}
void quick_sort(vector<int> &A, int l, int r)
{
    if (l < r)
    {
        int s = HoarePartition(A, l, r);
        quick_sort(A, l, s - 1);
        quick_sort(A, s + 1, r);
    }
}
void quick_sort(vector<int> &A)
{
    quick_sort(A, 0, A.size() - 1);
}

// =============== UNIQUE ELEMENTS =============== //
void unique_elements(vector<int> &A)
{
    int i = 0;
    while (i < A.size() - 1)
    {
        if (A[i] == A[i + 1])
        {
            A.erase(A.begin() + i);
        }
        else
        {
            i++;
        }
    }
}

// =============== MAIN FUNCTION =============== //
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    quick_sort(A);
    unique_elements(A);

    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
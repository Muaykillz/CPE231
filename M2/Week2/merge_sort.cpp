#include "bits/stdc++.h"

using namespace std;

// Function to merge two subarrays
void merge(vector<int> &A, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            A[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        A[k++] = L[i++];
    }

    while (j < n2)
    {
        A[k++] = R[j++];
    }
}

// Bottom-up merge sort
void BottomUpMergeSort(vector<int> &A, int n)
{
    if (n < 2)
        return;

    int i = 1;

    while (i < n)
    {
        int j = 0;
        while (j < n - i)
        {
            if (n < j + 2 * i)
            {
                merge(A, j, j + i, n);
            }
            else
            {
                merge(A, j, j + i, j + 2 * i);
            }
            j = j + 2 * i;
        }
        i = i * 2;
    }
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

    BottomUpMergeSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
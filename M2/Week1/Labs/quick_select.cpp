#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int quickSelect(vector<int> &arr, int left, int right, int k)
{
    if (left == right)
        return arr[left];

    int pivotIndex = partition(arr, left, right);

    if (pivotIndex == k) // ถ้า pivot อยู่ตำแหน่งที่น้อยที่สุดลำดับที่ k
        return arr[pivotIndex];
    else if (pivotIndex > k)                               // ถ้า pivot อยู่มากกว่าตำแหน่งที่ k
        return quickSelect(arr, left, pivotIndex - 1, k);  // ไปทางซ้าย
    else                                                   // ถ้า pivot น้อยกว่าตำแหน่งที่ k
        return quickSelect(arr, pivotIndex + 1, right, k); // ไปทางขวา
}

int main()
{
    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cin >> k;

    int result = quickSelect(arr, 0, n - 1, k - 1);

    cout << result << endl;

    return 0;
}
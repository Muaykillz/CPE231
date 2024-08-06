#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 1. Enter the number of n
    int n;
    cin >> n;

    // 2. Declare the array of pot and tree with size n
    vector<int> p(n);
    vector<int> t(n);

    // 3. Enter the height of pot
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    // 4. Enter the height of tree
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    // 5. sort the pot accending order
    sort(p.begin(), p.end());

    cout << "Pot: ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    // 6. sort the tree decending order
    sort(t.begin(), t.end(), greater<int>());

    cout << "Tree: ";
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;

    // 7. Declare the total height
    vector<int> p_t;

    // 8. calculate the total height
    for (int i = 0; i < n; i++)
    {
        p_t.push_back(p[i] + t[i]);
    }

    // 9. sort the total height
    sort(p_t.begin(), p_t.end());

    cout << "Total: ";
    for (int i = 0; i < n; i++)
    {
        cout << p_t[i] << " ";
    }
    cout << endl;

    // 10. Declare the sum of difference
    int sum_diff = 0;

    // 11. calculate the sum of difference
    for (int i = 0; i < n - 1; i++)
    {
        sum_diff += (p_t[i + 1] - p_t[i]);
    }

    // 12. show the result
    cout << sum_diff << endl;

    // 13. End the program
    return 0;
}
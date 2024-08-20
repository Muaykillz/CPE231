#include <bits/stdc++.h>

using namespace std;

// Check if a string is a palindrome
bool isPalindrome(const string &str)
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Convert decimal to binary
vector<bool> binary(int nBits, int n)
{
    vector<bool> bits(nBits, 0);
    int i = nBits - 1;
    while (n && i >= 0)
    {
        bits[i] = n % 2;
        n /= 2;
        i--;
    }
    return bits;
}

// Filter a string by bits
string filterByBits(const string &str, const vector<bool> &bits)
{
    string result = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (bits[i])
        {
            result += str[i];
        }
    }
    return result;
}

int main()
{

    string str;
    cin >> str;

    int nBits = str.size();

    int palindromes = 0;

    set<string> palindromeSet;

    // Check all possible combinations of bits
    for (int i = 0; i < pow(2, nBits); i++)
    {
        vector<bool> bits = binary(nBits, i);

        string filteredStr = filterByBits(str, bits);

        if (isPalindrome(filteredStr) && filteredStr.size() > 1 && filteredStr != "")
        {
            palindromeSet.insert(filteredStr); // Insert the palindrome into the set
        }
    }

    cout << palindromeSet.size() << endl;

    // Happy coding!

    return 0;
}

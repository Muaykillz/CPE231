#include <bits/stdc++.h>

using namespace std;

// Hash Function
int hashFunction(string s, int Z)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - 64;
    }
    return sum % Z;
}

// Insert Function
void insert(string s, vector<string> &hashTable, int Z)
{
    int index = hashFunction(s, Z);
    cout << index << endl;
    if (hashTable[index] == "")
    {
        hashTable[index] = s;
    }
    else
    {
        int i = 1;
        while (hashTable[(index + i) % Z] != "")
        {
            i++;
        }
        hashTable[(index + i) % Z] = s;
    }
}

int main()
{

    int Z, n;

    cin >> Z >> n;
    vector<string> hashTable(Z);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s, hashTable, Z);
    }

    for (int i = 0; i < Z; i++)
    {
        if (hashTable[i] == "")
        {
            cout << "NULL ";
        }
        else
        {
            cout << hashTable[i] << " ";
        }
    }

    return 0;
}
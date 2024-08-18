#include <bits/stdc++.h>

using namespace std;

// Factorial function
int factorial(int n, int &some_complexity_variable)
{
    if (n == 0)
    {
        return 1;
    }
    some_complexity_variable++; // for multiplication
    some_complexity_variable++; // for subtraction
    return n * factorial(n - 1, some_complexity_variable);
}

// Main
int main()
{
    int some_complexity_variable = 0;

    int n, v;
    cin >> n >> v;

    vector<int> ID[n];
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        some_complexity_variable++; // Counting comparison for the loop
    }

    int p;
    cin >> p;

    vector<int> XID[p];
    for (int j = 0; j < p; j++)
    {
        int xid;
        cin >> xid;
        some_complexity_variable++; // Counting comparison for the loop
    }

    // Factorial calculation
    int factorial_result = factorial(n - 1, some_complexity_variable);
    some_complexity_variable++; // for subtraction
    some_complexity_variable++; // for multiplication

    // Final output
    cout << factorial_result * (n - p) << endl;
    cout << "Total Basic Operations: " << some_complexity_variable << endl;

    return 0;
}

/*
  การวิเคราะห์ Time Complexity:
  การคูณเกิดขึ้นในฟังก์ชัน factorial และในขั้นตอนสุดท้ายของการคำนวณผลลัพธ์ ส่วนการลบเกิดขึ้นภายในฟังก์ชัน factorial
  ส่วนการเปรียบเทียบเกิดขึ้นภายในลูปและในกระบวนการเรียกซ้ำของฟังก์ชัน factorial
  ฟังก์ชัน factorial เรียกตัวเองซ้ำๆ ตาม input n ซึ่งทำให้มี Time Complexity เป็น O(n)
  นอกจากนี้ ลูปทั้งสองทำงานตามจำนวน n และ p ทำให้มี Time Complexity เป็น O(n) และ O(p)
  แต่เนื่องจากฟังก์ชัน factorial เป็น Dominant Term จึงทำให้ Time Complexity โดยรวมของโปรแกรมคือ O(n)
*/

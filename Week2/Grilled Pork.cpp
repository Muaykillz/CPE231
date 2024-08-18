#include <bits/stdc++.h>

using namespace std;

// Main
int main()
{
    int some_complexity_variable = 0; // ตัวนับ Basic Operation

    vector<int> P;
    for (int i = 0; i < 4; i++)
    {
        int p;
        cin >> p;
        P.push_back(p);
        some_complexity_variable++; // สำหรับการเปรียบเทียบในลูป
    }

    int n;
    cin >> n;
    vector<bool> Flags(n + 1, false);
    some_complexity_variable++; // สำหรับการคำนวณ n+1
    Flags[0] = true;

    for (int p : P)
    {
        for (int i = p; i <= n; i++)
        {
            Flags[i] = Flags[i] || Flags[i - p];
            some_complexity_variable += 2; // สำหรับการคำนวณและการเปรียบเทียบในลูป
        }
        some_complexity_variable++; // สำหรับการเปรียบเทียบในลูปภายนอก
    }

    for (int j = n; j >= 0; j--)
    {
        some_complexity_variable++; // สำหรับการเปรียบเทียบในลูป
        if (!Flags[j])
        {
            cout << j << endl;
            break;
        }
    }

    cout << "Total Basic Operations: " << some_complexity_variable << endl;

    return 0;
}

/*
การวิเคราะห์ Time Complexity:
ส่วนการสร้างลิสต์และรับค่าเริ่มต้นมี Complexity เป็น O(1) ลูปซ้อนสองชั้นมี Complexity O(n)
เนื่องจากลูปนอกมีจำนวนรอบคงที่ (4 รอบ) ส่วนลูปในวนตามค่า n ลูปสุดท้ายที่วนจาก n ลงมาก็มี Complexity O(n) เช่นกัน
ดังนั้น Time Complexity โดยรวมของโค้ดนี้คือ O(n) ซึ่งเป็นผลจาก Dominant Term ที่เป็นการวนลูปตามค่า n
*/

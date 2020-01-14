/*
 * 题目描述：给出一个长度不超过1000的字符串，判断它是不是回文(顺读，逆读均相同)的。
 * 
 * 输入描述：输入包括一行字符串，其长度不超过1000。
 *
 * 输出描述：可能有多组测试数据，对于每组数据，如果是回文字符串则输出"Yes!”，否则输出"No!"。
 *
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int i = 0;
        int j = s.length() - 1;
        bool flag = true;
        while (i < j) {
            if (s[i] != s[j]) {
                flag = false;
                break;
            }
            i++;
            j--;
        }
        if (flag)
            cout << "Yes!" << endl;
        else
            cout << "No!" << endl;
    }
    return 0;
}
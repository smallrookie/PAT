/*
 * 题目描述：输入一个长度不超过20的字符串，对所输入的字符串，按照ASCII码的大小从小到大进行排序，请输出排序后的结果。
 * 
 * 输入描述：一个字符串，其长度n<=20
 *
 * 输出描述：输入样例可能有多组，对于每组测试样例，按照ASCII码的大小对输入的字符串从小到大进行排序，输出排序后的结果。
 *
 */


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        sort(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}
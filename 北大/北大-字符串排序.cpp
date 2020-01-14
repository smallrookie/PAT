/*
 * 题目描述：编写一个程序，将输入字符串中的字符按如下规则排序(一个测试用例可能包含多组数据，请注意处理)。
 *          规则1：英文字母从 A 到 Z 排列，不区分大小写。
 *          如，输入： Type 输出： epTy
 *          规则2：同一个英文字母的大小写同时存在时，按照输入顺序排列。
 *          如，输入： BabA 输出： aABb
 *          规则3：非英文字母的其它字符保持原来的位置。
 *          如，输入： By?e 输出： Be?y
 *
 * 样例：
 *      输入：A Famous Saying: Much Ado About Nothing(2012/8).
 *
 *      输出：A aaAAbc dFgghh : iimM nNn oooos Sttuuuy (2012/8).
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    char val;
    int flag;
};

int main() {
    string s;
    vector<Node> v(1024);
    while (cin >> s) {
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                v[i].flag = 0;
            else {
                v[i].flag = 1;
                v[i].val = s[i];
            }
        }
        int idx = 0;
        for (int i = 'A'; i <= 'Z'; ++i) {
            for (int j = 0; j < len; ++j) {
                if (s[j] == i || s[j] == i + 32) {
                    while (v[idx].flag == 1)
                        idx++;
                    v[idx].val = s[j];
                    v[idx].flag = 1;
                }
            }
        }
        for (int i = 0; i < len; ++i)
            cout << v[i].val;
        cout << endl;
    }
    return 0;
}
/*
* 题目描述：读入数据string[ ]，然后读入一个短字符串。要求查找string[ ]中和短字符串的所有匹配，输出行号、匹配字符串。
*           匹配时不区分大小写，并且可以有一个用中括号表示的模式匹配。如“aa[123]bb”，就是说aa1bb、aa2bb、aa3bb都算匹配。
*
* 输入：输入有多组数据。每组数据第一行输入n(1<=n<=1000)，从第二行开始输入n个字符串（不含空格），接下来输入一个匹配字符串。
*
* 输出：输出匹配到的字符串的行号和该字符串（匹配时不区分大小写）。
*
* 示例：
*      输入：4
*            Aab
*            a2B
*            ab
*            ABB
*            a[a2b]b
*
*      输出：1 Aab
*            2 a2B
*            4 ABB
*
**/

#include <iostream>
#include <string>

using namespace std;

bool isLetter(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        return true;
    else
        return false;
}

bool isSame(char a, char b) {
    if (!isLetter(a) || !isLetter(b)) {
        if (a == b)
            return true;
        else
            return false;
    }
    else if ((a == b) || (a == b + 'A' - 'a') || (a == b + 'a' - 'A'))
        return true;
    else
        return false;
}

bool Bracket(string t, string p, int &pos_t, int &pos_p) {
    int i = pos_p + 1;
    while (p[pos_p] != ']')
        pos_p++;
    pos_p++;

    while (i < pos_p) {
        if (isSame(p[i], t[pos_t])) {
            pos_t++;
            return true;
        }
        i++;
    }
    return false;
}

bool Match(string t, string p) {

    int lenT = t.size();
    int lenP = p.size();

    int pos_t = 0;
    int pos_p = 0;
    while (pos_t < lenT && pos_p < lenP) {
        if (isSame(p[pos_p], t[pos_t])) {
            pos_t++;
            pos_p++;
        }
        else if (p[pos_p] == '[') {
            if (!Bracket(t, p, pos_t, pos_p))
                break;
        }
        else
            return false;
    }
    if (t[pos_t] == '\0' && p[pos_p] == '\0')
        return true;
    else
        return false;
}

int main() {

    int n;
    while (cin >> n) {

        string t[n], p;
        for (int i = 0; i < n; ++i)
            cin >> t[i];
        cin >> p;

        for (int i = 0; i < n; ++i) {
            if (Match(t[i], p))
                cout << i + 1 << " " << t[i] << endl;
        }
    }
    return 0;
}

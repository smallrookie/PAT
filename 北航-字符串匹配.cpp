/*
* ��Ŀ��������������string[ ]��Ȼ�����һ�����ַ�����Ҫ�����string[ ]�кͶ��ַ���������ƥ�䣬����кš�ƥ���ַ�����
*           ƥ��ʱ�����ִ�Сд�����ҿ�����һ���������ű�ʾ��ģʽƥ�䡣�硰aa[123]bb��������˵aa1bb��aa2bb��aa3bb����ƥ�䡣
*
* ���룺�����ж������ݡ�ÿ�����ݵ�һ������n(1<=n<=1000)���ӵڶ��п�ʼ����n���ַ����������ո񣩣�����������һ��ƥ���ַ�����
*
* ��������ƥ�䵽���ַ������кź͸��ַ�����ƥ��ʱ�����ִ�Сд����
*
* ʾ����
*      ���룺4
*            Aab
*            a2B
*            ab
*            ABB
*            a[a2b]b
*
*      �����1 Aab
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

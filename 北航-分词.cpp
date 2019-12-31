#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool nextVar(string s, int &index, string &next) {

    if (index >= s.length() - 1)
        return false;


    while (s[index] == '*' || s[index] == ' ')
        index++;

    int op = index;
    int ed = s.find(',', op);
    if (ed == string::npos)
        ed = s.find(';', op);

    index = ed + 1;
    if (op > ed)
        return false;
    next = s.substr(op, ed);
}

int main() {

    string s1, s2, next;
    while (getline(cin, s1)) {
        // getline(cin, s2);

        // 清理语句开头的空格
        int i = 0;
        while (s1[i] == ' ')
            s1.erase(i, i + 1);

        vector<string> v1;
        i = s1.find(' ');
        while (nextVar(s1, i, next))
            v1.push_back(next);

    }

    return 0;
}

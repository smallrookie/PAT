/*
*
* 题目描述：两个整数数组（无序，可有重复元素），判断两个整数数组是否相同。（重复元素的次数也要相同）。
*
**/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEqual(vector<int> &a, vector<int> &b) {

    vector<int>::iterator i;
    vector<int>::iterator j;
    for (i = a.begin(), j = b.begin(); i != a.end() && j != b.end(); ++i, ++j) {
        if (*i != *j)
            return false;
    }
    return true;
}

int main() {

    int n, m;
    while (cin >> n >> m) {

        if (n != m) {
            cout << "not equal" << endl;
            break;
        }

        int val;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            cin >> val;
            a.push_back(val);
        }
        for (int i = 0; i < m; ++i) {
            cin >> val;
            b.push_back(val);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (isEqual(a, b))
            cout << "equal" << endl;
        else
            cout << "not equal" << endl;
    }

    return 0;
}

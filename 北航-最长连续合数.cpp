/*
* ��Ŀ��������������[n, m]�������������������������Ρ�
*
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isCompositeNumber(int x) {
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0 && x != 2)
            return true;
    }
    return false;
}

int main() {

    int n, m;
    while (cin >> n >> m) {
        vector<int> v;
        for (int i = n; i <= m; ++i) {
            if (isCompositeNumber(i)) {
                v.push_back(i);
            }
        }
        sort(v.begin(), v.end());

        int index = 0;
        int maxLen = 1;
        int len = 1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i + 1] - v[i] == 1) {
                len++;
            }
            else {
                if (len > maxLen) {
                    maxLen = len;
                    index = i;
                }
                len = 1;
            }
        }

        for (int i = index - maxLen + 1; i <= index; ++i)
            cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}

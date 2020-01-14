/*
* ��Ŀ������������һ����������N����������n����������֡�Ҫ������������к����λ�����Լ�����λ������Ĵ������NΪż�����������������λ�������NΪ������������м�������ɡ�
*
**/

#include <iostream>
#include <algorithm>

using namespace std;

struct Digit {

    int index;
    int val;
};

bool cmp(Digit d1, Digit d2) {

    return d1.val > d2.val;
}

int main() {

    int n;
    while (cin >> n) {

        Digit d[n];
        for (int i = 0; i < n; ++i) {
            cin >> d[i].val;
            d[i].index = i + 1;
        }

        sort(d, d + n, cmp);

        int k = n / 2;
        if (n % 2 == 1) {
            cout << d[k].val << " " << d[k].index << endl;
        }
        else {
            cout << d[k - 1].val << " " << d[k - 1].index << endl;
            cout << d[k].val << " " << d[k].index << endl;
        }
    }

    return 0;
}

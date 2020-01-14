/*
* 题目描述：先输入一个整型数字N，接着输入n个无序的数字。要求输出升序排列后的中位数，以及该中位数输入的次序。如果N为偶数，则输出有两个中位数，如果N为奇数，输出最中间的数即可。
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

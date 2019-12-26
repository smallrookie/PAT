/*
* 题目描述：输入为两个数a，b。求出区间[a,b]之间所有相邻素数组成的等差数列。其中a>=2,b<100000
*
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(int n) {

    if (n == 1)
        return false;

    int t = sqrt(n);
    for (int i = 2; i <= t; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {

    int n, m;
    while (cin >> n >> m) {
        vector<int> v;
        for (int i = n; i <= m; ++i) {
            if(isPrime(i)) {
                v.push_back(i);
            }
        }
        sort(v.begin(), v.end());

        for (int i = 2; i < v.size();) {
            int first = v[i - 2];
            int second = v[i - 1];
            int third = v[i];

            int dif = second - first;
            if (third - second == dif) {
                cout << first << " " << second << " " << third << " ";

                int tmp = second;
                while (third - tmp == dif) {
                    tmp = third;
                    i++;
                    if (v[i] - tmp == dif) {
                        cout << v[i] << " ";
                    }
                }
                cout << endl;
            }
            else
                i++;
        }
    }

    return 0;
}

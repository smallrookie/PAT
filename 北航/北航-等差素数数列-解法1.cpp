/*
* 题目描述：输入为两个数a，b。求出区间[a,b]之间所有相邻素数组成的等差数列。其中a>=2,b<100000
*
**/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAX = 100010;

bool isPrime(int n)
{
    if (n == 1)
        return false;

    int t = sqrt(n);
    for (int i = 2; i <= t; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{

    bool flag[MAX];
    fill(flag, flag + MAX, true);

    int n, m;
    while (cin >> n >> m)
    {
        vector<int> v;
        for (int i = 2; i <= m; ++i)
        {
            if (flag[i] == false)
                continue;
            if (isPrime(i) && i >= n)
            {
                flag[i] = true;
                v.push_back(i);
            }
            for (int j = 1; i * j <= m; ++j)
                flag[i * j] = false;
        }

        bool op = false;
        bool ed = false;
        for (int i = 1; i < v.size(); ++i)
        {
            if (op && v[i] - v[i - 1] == v[i - 1] - v[i - 2])
                cout << v[i] << " ";
            else
            {
                op = false;
                if (ed)
                {
                    ed = false;
                    cout << endl;
                }
            }
            if (!op && i != v.size() - 1 && v[i - 1] + v[i + 1] == 2 * v[i])
            {
                op = true;
                ed = true;
                cout << v[i - 1] << " " << v[i] << " ";
            }
        }
        if (ed)
            cout << endl;
    }
    return 0;
}

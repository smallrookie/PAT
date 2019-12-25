/*
*
* 题目描述：给出一个整数序列S，其中有N个数，定义其中一个非空连续子序列T中所有数的和为T的“序列和”。
*           对于S的所有非空连续子序列T，求最大的序列和。 变量条件：N为正整数，N≤1000000，结果序列
*           和在范围（-2^63,2^63-1）以内。
*
* 输入：第一行为一个正整数N，第二行为N个整数，表示序列中的数。
*
* 输出：输入可能包括多组数据，对于每一组输入数据，仅输出一个数，表示最大序列和。
*
**/

#include <iostream>

using namespace std;

int list[1000001];
int dp[1000001];

int main() {

    int n;
    while (cin >> n) {

        for (int i = 1; i <= n; ++i) {
            cin >> list[i];
            dp[i] = list[i];
        }

        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i], dp[i - 1] + list[i]);
        }

        int ans = dp[1];
        for (int i = 1; i <= n; ++i) {
            if (ans < dp[i]) {
                ans = dp[i];
            }
        }

        cout << ans << endl;
    }

    return 0;
}

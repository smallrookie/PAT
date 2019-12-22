/*
* 题目描述：哈夫曼树，第一行输入一个数n，表示叶结点的个数。需要用这些
*           叶结点生产哈夫曼树，根据哈夫曼树的概念，这些结点有权值，即
*           weight，题目需要输出所有结点的值与权值的乘积之和。
*
* 输入：输入有多组数据。
*       每组第一行输入一个数n，接着输入n个叶结点（叶结点权值不超过100），
*       2 <= n <= 1000）。
*
* 输出：输出权值。
*
*
**/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 小根堆
priority_queue<int, vector<int>, greater<int>> Q;

int main() {
    int n;
    while (cin >> n) {

        while (!Q.empty())
            Q.pop();

        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            Q.push(x);
        }

        int ans = 0;
        while (Q.size() > 1) {
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            ans += a + b;
            Q.push(a + b);
        }
        cout << ans << endl;
    }
    return 0;
}

/*
* 
* 题目描述：某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通
           的城镇。省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不
           一定有直接的道路相连，只要互相间接通过道路可到即可），并要求铺设的公路总
           长度为最小。请计算最小的公路总长度。
* 输入描述：测试输入包含若干个测试用例。每个测试用例的第1行给出城镇数目N（< 1000）；
           随后的N(N-1)/2行对应城镇间的距离，每行给出一对正整数，分别是两个城镇的编
           号，以及此两城镇间的距离。为简单起见，城镇从1到N编号。当N为0时，输入结束，
           该用例不被处理。
* 输出描述：对每个测试用例，在1行里输出最小的公路总长度。
*
*
**/


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 101;
int Tree[N];

struct Edge {
    int a, b;
    int cost;
    bool operator <(const Edge &A) const {
        return cost < A.cost;
    }
}edge[6000];

int findRoot(int x) {
    if (Tree[x] == -1)
        return x;

    Tree[x] = findRoot(Tree[x]);
    return Tree[x];
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        for (int i = 1; i <= n * (n - 1) / 2; ++i)
            cin >> edge[i].a >> edge[i].b >> edge[i].cost;
        sort(edge + 1, edge + 1 + n * (n - 1) / 2);

        for (int i  = 1; i <= n; ++i)
            Tree[i] = -1;

        int ans = 0;
        for (int i = 1; i <= n * (n - 1) / 2; ++i) {
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);

            if (a != b) {
                Tree[a] = b;
                ans += edge[i].cost;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

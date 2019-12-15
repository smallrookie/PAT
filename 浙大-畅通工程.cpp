/*
* 
* 题目描述：某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通
           的城镇。省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不
           一定有直接的道路相连，只要互相间接通过道路可到即可）。问最少还需要建设多
           少条道路？
* 输入描述：测试输入包含若干个测试用例。每个测试用例的第1行给出两个正整数，分别是城镇
           数目N（< 1000）和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分
           别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。当N为0时，
           输入结束，该用例不被处理。
* 输出描述：对每个测试用例，在1行里输出最少还需建设的道路数目。
*
*
**/



#include <iostream>

using namespace std;

const int N = 1000;
int Tree[N];

int findRoot(int x) {
    if (Tree[x] == -1)
        return x;
    Tree[x] = findRoot(Tree[x]);
    return Tree[x];
}

int main() {

    int n, m;
    while (cin >> n >> m) {

    	if (n == 0)
    		break;

        for (int i = 1; i <= n; ++i) {
            Tree[i] = -1;
        }

        while (m != 0) {
            int a, b;
            cin >> a >> b;
            a = findRoot(a);
            b = findRoot(b);
            if (a != b)
                Tree[a] = b;
            m--;
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (Tree[i] == -1)
                ans++;
        }

        cout << ans - 1 << endl;

    }

    return 0;
}

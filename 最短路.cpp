/*
* 题目描述：在每年的校赛里，所有进入决赛的同学都会获得一件很漂亮的T-shirt。
*           但每当我们的工作人员把上百件的衣服从商店运回到赛场的时候，却是
*           非常累的！所以现在他们想要寻找最短的从商店到赛场的路线，你可以
*           帮助他们吗？
*
* 输入：输入包括多组数据。每组数据第一行是两个整数N、M（N<=100, M<=10000）,
*       N表示成都的大街上有几个路口，标号为1的路口是商店所在地，标号为N的路口
*       是赛场所在地，M则表示在成都有几条路。N=M=0表示输入结束。接下来M行，每
*       行包括3个整数A、B、C（1<=A, B<=N, 1<=C<=1000），表示在路口A与路口B之间
*       有一条路，我们的工作人员需要C分钟的时间走过这条路。输入保证至少存在1条
*       商店到赛场的路线。
*
* 输出：对于每组输入，输出一行，表上工作人员从商店走到赛场的最短时间。
*
**/

#include <iostream>

using namespace std;

int ans[101][101];

int main() {

    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                ans[i][j] = -1;
            }
            ans[i][i] = 0;
        }

        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;

            // 无向图
            ans[a][b] = c;
            ans[b][a] = c;
        }

        // Floyd 算法
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (ans[i][k] == -1 || ans[k][j] == -1) {
                        continue;
                    }
                    if (ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j]) {
                        ans[i][j] = ans[i][k] + ans[k][j];
                    }
                }
            }
        }

        cout << ans[1][n] << endl;
    }

    return 0;
}

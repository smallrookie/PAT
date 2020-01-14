/*
 * 题目描述：会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），
            使它们谁也不能被吃掉！这就是著名的八皇后问题。 对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，
            其中bi为相应摆法中第i行皇后所处的列数。已经知道8皇后问题一共有92组解（即92个不同的皇后串）。 给出一个数b，要求输出第b个串。
            串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。
 * 输入描述：每组测试数据占1行，包括一个正整数b(1 <= b <= 92)
 * 输出描述：输出有n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串。
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 棋盘
bool chessBoard[8][8];
// 解空间
int res[92];
// 临时解
int tmp[8];
// 个数标记
int flag = 0;

// 转换为十进制
int translate(int a[]) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        count *= 10;
        count += a[i];
    }
    return count;
}

// x->行，y->列
bool isPut(int x, int y) {
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < 8; ++j)
            if (chessBoard[i][j] && (j == y || j == y - (x - i) || j == y + (x - i)))
                return false;
    return true;
}

void DFS(int x) {
    if (x == 8) {
        res[flag++] = translate(tmp);
        return;
    }
    for (int y = 0; y < 8; ++y) {
        if (isPut(x, y)) {
            chessBoard[x][y] = true;
            tmp[x] = y + 1;
            DFS(x + 1);
            chessBoard[x][y] = false;
        }
    }
}

int main() {
    // 初始化棋盘
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            chessBoard[i][j] = false;
    DFS(0);
    sort(res, res + 92);
    
    int n;
    while (cin >> n) {
        cout << res[n - 1] << endl;
    }
    return 0;
}
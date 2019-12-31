/*
* 题目描述：输入是N条线段，每条线段由两个坐标点连接而成（每个坐标点都不相同），当两条线段首尾相接则称为这两条线段相连，问这些线段从左到右相连的最大长度（相连的线段数目）是多少？
*
**/

#include <iostream>
#include <algorithm>

using namespace std;

struct line {

    int lx;
    int ly;

    int rx;
    int ry;

    int len;
}l[1000];

bool cmp(line l1, line l2) {

    return l1.len > l2.len;
}

int main() {

    int n;
    while (cin >> n) {

        for (int i = 0; i < n; ++i) {
            cin >> l[i].lx >> l[i].ly >> l[i].rx >> l[i].ry;
            l[i].len = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (l[i].lx == l[j].rx && l[i].ly == l[j].ry) {
                    l[i].lx = l[j].lx;
                    l[i].ly = l[j].ly;

                    l[j].rx = l[i].rx;
                    l[j].ry = l[i].ry;

                    l[i].len += l[j].len;
                    l[j].len = l[i].len;
                }
                else if (l[i].rx == l[j].lx && l[i].ry == l[j].ly) {
                    l[i].rx = l[j].rx;
                    l[i].ry = l[j].ry;

                    l[j].rx = l[i].lx;
                    l[j].ry = l[i].ly;

                    l[j].len += l[i].len;
                    l[i].len = l[j].len;
                }
            }
        }

        sort(l, l + n, cmp);
        cout << l[0].len << " " << "( " << l[0].lx << ", " << l[0].ly << " )" << endl;
    }

    return 0;
}

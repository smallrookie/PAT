/*
* ��Ŀ������������N���߶Σ�ÿ���߶���������������Ӷ��ɣ�ÿ������㶼����ͬ�����������߶���β������Ϊ�������߶�����������Щ�߶δ�������������󳤶ȣ��������߶���Ŀ���Ƕ��٣�
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

/*
* ��Ŀ������������������һ������һ����n����ʾҶ���ĸ�������Ҫ����Щ
*           Ҷ��������������������ݹ��������ĸ����Щ�����Ȩֵ����
*           weight����Ŀ��Ҫ������н���ֵ��Ȩֵ�ĳ˻�֮�͡�
*
* ���룺�����ж������ݡ�
*       ÿ���һ������һ����n����������n��Ҷ��㣨Ҷ���Ȩֵ������100����
*       2 <= n <= 1000����
*
* ��������Ȩֵ��
*
*
**/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// С����
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

/**
 * 
 * 题目描述：输入一个整数n，输出n的阶乘（每组测试用例可能包含多组数据，请注意处理）
 *
 * 输入描述：一个整数n(1<=n<=20)
 * 
 * 输出描述：n的阶乘
 *
 */

#include <iostream>

using namespace std;

long func(long n) {
	if (n == 1) return 1;
	return n * func(n - 1);
}

int main() {
	long n;
	while (cin >> n) {
		long res = func(n);
		cout << res << endl;
	}

	return 0;
}
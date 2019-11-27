/**
 *
 * 题目描述：输入n， 求y1=1!+3!+...m!(m是小于等于n的最大奇数） y2=2!+4!+...p!(p是小于等于n的最大偶数)。
 * 
 * 输入描述：每组输入包括1个整数：n
 * 
 * 输出描述：可能有多组测试数据，对于每组数据，输出题目要求的y1和y2
 *
 */


#include <iostream>

using namespace std;

int main() {
	long n;
	long tmp = 1, evenSum = 0, oddSum = 0;
	while (cin >> n) {
		for (long i = 1; i <= n; ++i) {
			tmp *= i;
			if (i % 2 == 0) evenSum += tmp;
			else oddSum += tmp;
		}
		cout << oddSum << " " << evenSum << endl;
	}
	return 0;
}
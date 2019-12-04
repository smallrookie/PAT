/*
 * 题目描述：请输入字符串，最多输入4 个字符串，要求后输入的字符串排在前面，
            例如：输入：EricZ

                 输出：1=EricZ

                 输入：David

                 输出：1=David 2=EricZ

                 输入：Peter

                 输出：1=Peter 2=David 3=EricZ

                 输入：Alan

                 输出：1=Alan 2=Peter 3=David 4=EricZ

                 输入：Jane

                 输出：1=Jane 2=Alan 3=Peter 4=David
 *
 * 输入描述：第一行为字符串个数m，接下来m行每行一个字符床，m不超过100，每个字符床长度不超过20。
 * 输出描述：输出m行，每行按照样例格式输出，注意用一个空格隔开。
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        string s[100];
		int i, j, k;
        for (i = 0; i < n; ++i) {
            cin >> s[i];
			for (j = i, k = 1; j >=0 && k <= 4; --j, ++k) {
				cout << k << "=" << s[j] << " ";
			}
			cout << endl;
        }
	}
    return 0;
}
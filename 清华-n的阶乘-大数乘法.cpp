#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bigNumMul(vector<int> a, vector<int> b) {
	int m = a.size();
	int n = b.size();
	vector<int> result(m + n);
	
	// 累加，留一位防止最高位进制
	int i, j;
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			result[i + j + 1] += a[i] * b[j];
		}
	}

	// 每位进制
	for (i = result.size() - 1; i > 0; --i) {
		if (result[i] >= 10) {
			result[i - 1] += result[i] / 10;
			result[i] = result[i] % 10;
		}
	}
	return result;
}

vector<int> intToVec(int n) {
	vector<int> result;
	if (n < 10) {
		result.push_back(n);
	}
	else {
		while (n) {
			result.push_back(n % 10);
			n /= 10;
		}
		reverse(result.begin(), result.end());
	}
	return result;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> result(1);
		result[0] = 1;
		for (int i = 1; i <= n; ++i) {
			vector<int> a = intToVec(i);
			result = bigNumMul(result, a);
		}

		int begin = 0;
		for (int i = 0; i < result.size(); ++i) {
			if (result[i] != 0)
				begin = 1;
			if (begin)
				cout << result[i];
		}
		cout << endl;
	}
	return 0;
}

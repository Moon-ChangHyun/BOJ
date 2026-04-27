// 0ms, 2020KB

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int x, b;
	cin >> x >> b;
	if (x == 0) {
		cout << '0';
		return 0;
	}
	vector<char> retR;//부호없는 뒤집힌 정답
	int sign;
	if (b > 0) {
		sign = x > 0 ? 1 : -1;
		x *= sign;
		while (x >= b) {
			int q = x / b;
			retR.push_back((x - q * b) + '0');
			x = q;
		}
	}
	else {
		sign = 1;
		while (x < 0 || -b <= x) {
			int q = x > 0 ? x / b : (x + b + 1) / b;
			retR.push_back((x - q * b) + '0');
			x = q;
		}
	}
	if (x)
		retR.push_back(x + '0');
	if (sign == -1)
		cout << '-';
	for (auto rIter = retR.rbegin(); rIter != retR.rend(); ++rIter)
		cout << *rIter;
}
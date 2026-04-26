// 12ms, 2024KB

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> nums(4);
const char ops[4] = { '+', '-', '*', '/' };
const double epsilon = 0.0000001;

bool isEq24(const vector<char> & exp) {
	vector<double> stk;
	double x, y;

	for (char c : exp) {
		if ('0' < c && c <= '9') {
			stk.push_back(c - '0');
		}
		else {
			y = stk.back(); stk.pop_back();
			x = stk.back(); stk.pop_back();
			if (c == '+') {
				stk.push_back(x + y);
			}
			else if (c == '-') {
				stk.push_back(x - y);
			}
			else if (c == '*') {
				stk.push_back(x * y);
			}
			else {
				if (y == 0) 
					return false;
				stk.push_back(x / y);
			}
		}
	}
	return abs(stk[0] - 24) <= epsilon;
}

bool checkPerm () {
	vector<char> exp(7); //후위표기식
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				exp[0] = nums[0];
				exp[1] = nums[1];
				exp[2] = ops[i];
				exp[3] = nums[2];
				exp[4] = ops[j];
				exp[5] = nums[3];
				exp[6] = ops[k];
				if (isEq24(exp))
					return true;

				exp[4] = nums[3];
				exp[5] = ops[j];
				if (isEq24(exp))
					return true;

				exp[2] = nums[2];
				exp[3] = ops[i];
				exp[4] = ops[j];
				exp[5] = nums[3];
				if (isEq24(exp))
					return true;

				exp[4] = nums[3];
				exp[5] = ops[j];
				if (isEq24(exp))
					return true;

				exp[3] = nums[3];
				exp[4] = ops[i]; 
				if (isEq24(exp))
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	for (cin >> T; ~--T;) {
		for (auto& num : nums) {
			cin >> num;
			num += '0';
		}

		sort(nums.begin(), nums.end());
		bool sat = false;
		do {
			if (checkPerm()) {
				sat = true;
				break;
			}
		} while (next_permutation(nums.begin(), nums.end()));
		cout << (sat ? "YES\n" : "NO\n");
	}
}
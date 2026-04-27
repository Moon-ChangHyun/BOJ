// 12ms, 4600KB

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> stk;
	vector<int> idx_open(n, -1);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			stk.push_back(i);
		}
		else if (!stk.empty()) {
			int x = stk.back(); stk.pop_back();
			if (x > 0 && idx_open[x - 1] != -1) {
				idx_open[i] = idx_open[x - 1];
			}
			else {
				idx_open[i] = x;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (idx_open[i] != -1)
			ans = max(ans, i - idx_open[i] + 1);
	cout << ans;
}
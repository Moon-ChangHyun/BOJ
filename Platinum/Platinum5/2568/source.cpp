// 36ms, 3388KB

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<int, int>> line;
	vector<int> dp;
	vector<int> ind;
	int n;
	cin >> n;
	line.resize(n);
	ind.resize(n);
	dp.reserve(n);
	for (int i = 0; i < n; ++i)
		cin >> line[i].first >> line[i].second;
	sort(line.begin(), line.end());
	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(dp.begin(), dp.end(), line[i].second);
		if (it == dp.end()) {
			dp.push_back(line[i].second);
			ind[i] = dp.size() - 1;
		}
		else {
			*it = line[i].second;
			ind[i] = it - dp.begin();
		}
	}
	cout << n - dp.size() << '\n';
	int lisIdx = dp.size() - 1;
	for (int i = n; --i >= 0;) {
		if (ind[i] == lisIdx) {
			dp[lisIdx--] = i;
		}
	}
	++lisIdx;
	for (int i = 0; i < n; ++i) {
		if (i == dp[lisIdx]) {
			++lisIdx;
		}
		else {
			cout << line[i].first << '\n';
		}
	}
}
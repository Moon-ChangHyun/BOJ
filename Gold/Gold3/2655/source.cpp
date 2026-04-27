// 0ms, 2160KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> area;
vector<int> height;
vector<int> weight;
vector<int> ordered; // area 내림차순

vector<vector<int>> dp;

int func(int idx, int prev) {
	if (idx > N)
		return 0;

	int& ret = dp[idx][prev];
	if (ret != -1)
		return ret;

	ret = func(idx + 1, prev);
	int& sortedIdx = ordered[idx];
	if (weight[sortedIdx] < weight[prev]) {
		ret = max(ret, func(idx + 1, sortedIdx) + height[sortedIdx]);
	}

	return ret;
}

void reconstruct() {
	vector<int> ans;
	int prevSel = 0;
	for (int i = 1; i < N; ++i) {
		if (dp[i][prevSel] != dp[i + 1][prevSel]) {
			prevSel = ordered[i];
			ans.push_back(prevSel);
		}
	}
	if (weight[prevSel] > weight[ordered[N]])
		ans.push_back(ordered[N]);

	cout << ans.size() << '\n';
	for (auto rIter = ans.rbegin(); rIter != ans.rend(); ++rIter) {
		cout << *rIter << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	area.resize(N + 1);
	height.resize(N + 1);
	weight.resize(N + 1);
	ordered.resize(N + 1);
	area[0] = weight[0] = 10001;
	height[0] = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> area[i] >> height[i] >> weight[i];
		ordered[i] = i;
	}

	sort(ordered.begin() + 1, ordered.end(), [](int a, int b) {
		return area[a] > area[b];
	});

	dp.resize(N + 1, vector<int>(N + 1, -1));
	func(1, 0);
	reconstruct();
}
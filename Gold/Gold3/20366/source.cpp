// 24ms, 6764KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> arr(N);
	for (auto& x : arr)
		cin >> x;
	
	vector<pair<int, pair<int, int>>> ordered;

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			ordered.emplace_back(arr[i] + arr[j], make_pair(i, j));
		}
	}

	sort(ordered.begin(), ordered.end());

	int ans = 2'000'000'001;
	for (int i = 1; i < ordered.size(); ++i) {
		if (ans <= ordered[i].first - ordered[i - 1].first)
			continue;
		
		auto& p1 = ordered[i - 1].second;
		auto& p2 = ordered[i].second;

		if (p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second)
			ans = ordered[i].first - ordered[i - 1].first;
	}

	cout << ans;
}
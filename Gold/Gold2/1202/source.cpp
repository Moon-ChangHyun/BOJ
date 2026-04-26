// 240ms, 18492KB

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	long long ret = 0;
	cin >> N >> K;
	vector<pair<int, int>> gem(N);
	for (auto& g : gem) {
		cin >> g.second >> g.first;
	}
	sort(gem.begin(), gem.end(), greater<>());
	multiset<int> bag;
	for (int i = 0; i != K; ++i) {
		int x;
		cin >> x;
		bag.insert(x);
	}
	for (auto& g : gem) {
		auto it = bag.lower_bound(g.second);
		if (it != bag.end()) {
			ret += g.first;
			bag.erase(it);
		}
	}
	cout << ret;
}
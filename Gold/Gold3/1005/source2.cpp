// 144ms, 2832KB

#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

int N, K, W;
vector<int> delay;
vector<vector<int>> adj;
vector<int> cache;

int f(int pos)
{
	if (adj[pos].size() == 0)
		return delay[pos];
	int& ret = cache[pos];
	if (ret != -1)
		return ret;
	for (auto& precede : adj[pos]) {
		ret = max(f(precede), ret);
	}
	return ret += delay[pos];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	for (cin >> T; ~--T; ) {
		cin >> N >> K;
		delay.resize(N + 1);
		adj.resize(N + 1);
		for (auto& list : adj)
			list.clear();

		for (int i = 1; i <= N; ++i) {
			cin >> delay[i];
		}
		for (int i = 0; i != K; ++i) {
			int a, b;
			cin >> a >> b;
			adj[b].push_back(a);
		}
		cin >> W;
		cache.clear();
		cache.resize(N + 1, -1);
		cout << f(W) << '\n';
	}
}
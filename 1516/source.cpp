#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> reqTime;
vector<vector<int>> adj;
vector<int> cache;
int dfs(int num) {
	int& ret = cache[num];
	if (ret != -1) return ret;
	ret = 0;
	for (auto iter = adj[num].begin(); iter != adj[num].end(); ++iter)
		ret = max(ret, dfs(*iter));
	return ret += reqTime[num];
}
int main() {
	int N;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	reqTime.resize(N + 1);
	adj.resize(N + 1);
	cache.resize(N + 1, -1);
	for (int i = 1; i <= N; ++i) {
		cin >> reqTime[i];
		while (true) {
			int x;
			cin >> x;
			if (x == -1) break;
			adj[i].push_back(x);
		}
	}
	for (int i = 1; i <= N; ++i)
		cout << dfs(i) << '\n';
}
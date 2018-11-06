#include<iostream>
#include<vector>
using namespace std;
int n, k;
vector<vector<bool>> adj;
vector<int> bMatch;
vector<bool> aVisit;
bool dfs(int a) {
	if (aVisit[a]) return false;
	aVisit[a] = true;
	for (int i = 1; i <= n; ++i) {
		if (adj[a][i]) {
			if (bMatch[i] == 0 || dfs(bMatch[i])) {
				bMatch[i] = a;
				return true;
			}
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	adj.resize(n + 1, vector<bool>(n + 1, false));
	bMatch.resize(n + 1, 0);
	aVisit.resize(n + 1);
	for (int i = 1; i <= k; ++i) {
		int r, c;
		cin >> r >> c;
		adj[r][c] = true;
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		fill(aVisit.begin(), aVisit.end(), false);
		if (dfs(i)) ++ret;
	}
	cout << ret;
}
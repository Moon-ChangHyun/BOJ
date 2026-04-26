// 968ms, 5900KB

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int adj[1001][1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p, q, ret = -987654321;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			int x;
			cin >> x;
			if(x == 0 && i != j) x = 987654321;
			adj[i][j] = x;
		}
	}
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}
	cin >> p >> q;
	vector<pair<int, int>> aVec(p), bVec(q);
	for(int i = 0; i != p; ++i)
		cin >> aVec[i].first >> aVec[i].second;
	for(int i = 0; i != q; ++i)
		cin >> bVec[i].first >> bVec[i].second;
	for(auto oIter : aVec) {
		for(auto iIter : bVec) {
			ret = max(ret, oIter.second + iIter.second - adj[oIter.first][iIter.first]);
		}
	}
	cout << ret;
}
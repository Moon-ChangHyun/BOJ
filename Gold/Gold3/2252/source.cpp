// 24ms, 3948KB

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> adj;
vector<int> order;
vector<bool> visit;

void dfs(int here) {
	visit[here] = true;
	for (auto there : adj[here])
		if (!visit[there]) dfs(there);
	order.push_back(here);
}

int main() {
    ios::sync_with_stdio(false);
	int n, m;
    cin >> n >> m;
	adj.resize(n + 1);
	visit.resize(n + 1, false);
    order.reserve(n + 1);
	for (int i = 0; i != m; ++i) {
		int a, b;
        cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i)
		if (!visit[i]) dfs(i);
	for (int i = n; ~--i;)
        cout << order[i] << ' ';
}
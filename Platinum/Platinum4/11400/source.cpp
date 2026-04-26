// 220ms, 14472KB

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int V, E, cnt;
vector<vector<int>> adj;
vector<int> discover;
vector<pair<int,int>> bridge;
vector<int> parent;

int getBridge(int here) {
	discover[here] = ++cnt;
	int ret = discover[here];
	for(auto there : adj[here]) {
		if(discover[there] == -1) { // 트리간선
			parent[there] = here;
			int subtree = getBridge(there);
			if(subtree > discover[here]) {
				if(here < there)
					bridge.push_back({here, there});
				else
					bridge.push_back({there, here});
			}
			ret = min(ret, subtree);
		}
		else {// 역방향 간선
			if(there == parent[here])
				continue;
			ret = min(ret, discover[there]);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	adj.resize(V + 1);
	discover.resize(V + 1, -1);
	parent.resize(V + 1, -1);
	for(int i = 0; i != E; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	getBridge(1);
	cout << bridge.size() << '\n';
	sort(bridge.begin(), bridge.end());
	for(auto iter : bridge)
		cout << iter.first << ' ' << iter.second << '\n';
}
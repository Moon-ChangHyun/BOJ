#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> visit;
vector<vector<pair<int, int>>> adj;
int V;

pair<int, int> dfs(int x) {
	visit[x] = true;
	int farNode = x, farDist = 0;
	for (auto& iter : adj[x]) {
		if (visit[iter.first])
			continue;
		auto tmp = dfs(iter.first);
		if (tmp.second + iter.second > farDist) {
			farNode = tmp.first;
			farDist = tmp.second + iter.second;
		}
	}
	return { farNode, farDist };
}

int main() {
	scanf("%d", &V);
	visit.resize(V + 1, false);
	adj.resize(V + 1);
	for (int i = 1; i != V; ++i) {
		int par, chi, wei;
		scanf("%d%d%d", &par, &chi, &wei);
		adj[par].push_back({ chi, wei });
		adj[chi].push_back({ par, wei });
	}
	auto tmp = dfs(1);
	fill(visit.begin(), visit.end(), false);
	printf("%d", dfs(tmp.first).second);
}
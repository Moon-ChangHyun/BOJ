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
	for (int i = 0; i != V; ++i) {
		int curNode;
		scanf("%d", &curNode);
		while (true) {
			int node, dist;
			scanf("%d", &node);
			if (node == -1)
				break;
			scanf("%d", &dist);
			adj[curNode].push_back({ node, dist });
		}
	}
	auto tmp = dfs(1);
	fill(visit.begin(), visit.end(), false);
	printf("%d", dfs(tmp.first).second);
}
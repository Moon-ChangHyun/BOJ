// 36ms, 3788KB

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int v, e, cnt, numCutVertex;
vector<vector<int>> adj;
vector<int> discovered;
vector<bool> isCutVertex;
int findCutVertex(int here, bool isRoot) {
	discovered[here] = ++cnt;
	int ret = discovered[here];
	int children = 0;
	for (auto& there : adj[here]) {
		if (!discovered[there]) {
			++children;
			int subtree = findCutVertex(there, false);
			if (!isRoot && subtree >= discovered[here]) {
				if (!isCutVertex[here]) {
					isCutVertex[here] = true;
					++numCutVertex;
				}
			}
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
	}
	if (isRoot && 1 < children) {
		isCutVertex[here] = true;
		++numCutVertex;
	}
	return ret;
}

int main() {
	scanf("%d%d", &v, &e);
	adj.resize(v + 1);
	isCutVertex.resize(v + 1);
	discovered.resize(v + 1);
	for (int i = 0; i != e; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= v; ++i) {
		if (!discovered[i])
			findCutVertex(i, true);
	}
	printf("%d\n", numCutVertex);
	for (int i = 1; i <= v; ++i) {
		if (isCutVertex[i])
			printf("%d ", i);
	}
}
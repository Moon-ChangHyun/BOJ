#include<cstdio>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
int n, m;
vector<list<int>> adj;
vector<int> order;
vector<bool> visit;
void dfs(int here) {
	visit[here] = true;
	for (auto iter : adj[here])
		if (!visit[iter]) dfs(iter);
	order.push_back(here);
}
int main() {
	scanf("%d%d", &n, &m);
	adj.resize(n);
	visit.resize(n, false);
	for (int i = 0; i != m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a - 1].push_back(b - 1);
	}
	for (int i = 0; i != n; ++i)
		if (!visit[i]) dfs(i);
	for (auto rIter = order.rbegin(); rIter != order.rend(); ++rIter)
		printf("%d ", *rIter + 1);
}
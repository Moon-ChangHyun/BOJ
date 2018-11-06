#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> visit;
int n, m, src, dst;

bool bfs(int w) {
	queue<int> q;
	q.push(src);
	visit[src] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == dst) {
			return true;
		}
		for (auto& iter : adj[here]) {
			if (!visit[iter.second] && iter.first >= w) {
				q.push(iter.second);
				visit[iter.second] = true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	adj.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 0; i != m; ++i) {
		int s, d, c;
		scanf("%d%d%d", &s, &d, &c);
		adj[s].push_back({ c, d });
		adj[d].push_back({ c, s });
	}
	scanf("%d%d", &src, &dst);
	int a = 1000000000;
	while (!bfs(a)) {
		a >>= 1;
		visit.assign(n + 1, false);
	}
	int b = a << 1;
	while ((a + 1) != b) {
		visit.assign(n + 1, false);
		int c = (a + b) >> 1;
		if (bfs(c)) {
			a = c;
		}
		else {
			b = c;
		}
	}
	printf("%d", a);
}
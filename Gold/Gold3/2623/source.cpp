//0ms, 1228KB

#include<cstdio>
#include<vector>
using namespace std;
int N, M;
vector<vector<int>> adj;
vector<bool> visit, printed;
vector<int> res;

bool dfs(int num) {
	visit[num] = true;
	for (auto next : adj[num]) {
		if (printed[next]) continue;
		if (visit[next] || !dfs(next)) return false;
	}
	res.push_back(num);
	printed[num] = true;
	return true;
}

int main() {
	scanf("%d%d", &N, &M);
	adj.resize(N + 1);
	visit.resize(N + 1, false);
	printed.resize(N + 1, false);
	res.reserve(N);
	for (int i = 0; i < M; ++i) {
		int l, x;
		scanf("%d%d", &l, &x);
		for (int j = 1; j < l; ++j) {
			int y;
			scanf("%d", &y);
			adj[y].push_back(x);
			x = y;
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (!visit[i]) dfs(i);
	}
	if (res.size() != N)
		printf("0");
	else
		for (auto val : res)
			printf("%d\n", val);
}
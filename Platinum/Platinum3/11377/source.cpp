//1160ms, 11788KB

#include <cstdio>
#include <list>
#include <vector>
#include <array>
using namespace std;
int N, M, K;
vector<list<int>> adj;
array<int, 1001> bMatch;
array<bool, 1001> aVisit;
bool dfs(int a) {
	if (aVisit[a]) return false;
	aVisit[a] = true;
	for (auto& iter : adj[a]) {
		if (bMatch[iter] == 0 || dfs(bMatch[iter])) {
			bMatch[iter] = a;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	adj.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		int wn;
		scanf("%d", &wn);
		for (int j = 0; j != wn; ++j) {
			int w;
			scanf("%d", &w);
			adj[i].push_back(w);
		}
	}
	int ret1 = 0;
	for (int i = 1; i <= N; ++i) {
		aVisit.fill(0);
		if (dfs(i))
			++ret1;
	}
	int ret2 = 0;
	for (int i = 1; i <= N; ++i) {
		aVisit.fill(0);
		if (dfs(i))
			if (++ret2 == K)
				break;
	}
	printf("%d", ret1 + ret2);
}
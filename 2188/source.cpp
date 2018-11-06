#include <iostream>
#include <array>
using namespace std;
int N, M;
array<array<bool, 201>, 201> adj;
array<int, 201> bMatch;
array<bool, 201> aVisit;
bool dfs(int a) {
	if (aVisit[a]) return false;
	aVisit[a] = true;
	for (int i = 1; i <= M; ++i) {
		if (adj[a][i]) {
			if (bMatch[i] == 0 || dfs(bMatch[i])) {
				bMatch[i] = a;
				return true;
			}
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		int wn;
		scanf("%d", &wn);
		for (int j = 0; j != wn; ++j) {
			int w;
			scanf("%d", &w);
			adj[i][w] = true;
		}
	}
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		aVisit.fill(0);
		if (dfs(i)) ++ret;
	}
	printf("%d", ret);
}
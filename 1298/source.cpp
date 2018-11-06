#include <iostream>
#include <array>
using namespace std;
int N, M;
array<array<bool, 101>, 101> adj;
array<int, 101> bMatch;
array<bool, 101> aVisit;
bool dfs(int a) {
	if (aVisit[a]) return false;
	aVisit[a] = true;
	for (int i = 1; i <= N; ++i) {
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
	int p, n;
	for (int i = 0; i != M; ++i) {
		scanf("%d%d", &p, &n);
		adj[p][n] = true;
	}
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		aVisit.fill(0);
		if (dfs(i)) ++ret;
	}
	printf("%d", ret);
}
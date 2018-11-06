#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<bool>> adj;
vector<bool> aVisit;
vector<int> bMatch;

bool dfs(int a) {
	if (aVisit[a]) return false;
	aVisit[a] = true;
	for (int i = 1; i != bMatch.size(); ++i) {
		if (adj[a][i])
			if (bMatch[i] == 0 || dfs(bMatch[i])) {
				bMatch[i] = a;
				return true;
			}
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	adj.resize(2 * n, vector<bool>(2 * n));
	bMatch.resize(2 * n);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != n; ++j) {
			int x;
			scanf("%d", &x);
			if (x)
				adj[i + j + 1][i - j + n] = true;
		}
	}
	int ret = 0;
	for (int i = 1; i != adj.size(); ++i) {
		aVisit = vector<bool>(2 * n);
		if (dfs(i)) ++ret;
	}
	printf("%d", ret);
}
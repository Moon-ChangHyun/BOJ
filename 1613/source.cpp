#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
int main() {
	int n, k, a, b;
	scanf("%d%d", &n, &k);
	vector<bitset<401>> v(n + 1);
	for (int i = 0; i != k; ++i) {
		scanf("%d%d", &a, &b);
		v[b] |= v[a];
		v[b][a] = true;
		for (int j = 1; j <= n; ++j)
			if (v[j][b]) v[j] |= v[b];
	}
	scanf("%d", &k);
	for (int i = 0; i != k; ++i) {
		scanf("%d%d", &a, &b);
		if (v[a][b]) printf("1\n");
		else if (v[b][a]) printf("-1\n");
		else printf("0\n");
	}
}
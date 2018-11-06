#include<cstdio>
#include<algorithm>
using namespace std;
int n, link[16][16], cache[16][65535];
int f(int p, unsigned short visit) {
	visit |= (1 << p);
	if (visit == (1 << n) - 1)
		return link[p][0];
	int& ret = cache[p][visit];
	if (ret) return ret;
	ret = 987654321;
	for (int next = 0; next != n; ++next) {
		if (link[p][next] == 987654321 || (visit & (1 << next))) continue;
		ret = min(ret, link[p][next] + f(next, visit));
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j) {
			scanf("%d", &link[i][j]);
			if (link[i][j] == 0)
				link[i][j] = 987654321;
		}
	printf("%d", f(0, 0));
}
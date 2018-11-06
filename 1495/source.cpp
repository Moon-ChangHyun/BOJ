#include<cstdio>
#include<algorithm>
using namespace std;

int n, s, m;
int v[100];
int cache[100][1000];
int f(int trk, int vol) {
	if (vol < 0 || vol > m)
		return -1;
	if (trk == n)
		return vol;
	int& ret = cache[trk][vol - 1];
	if (ret)
		return ret;
	return ret = max(f(trk + 1, vol + v[trk]), f(trk + 1, vol - v[trk]));
}

int main() {
	scanf("%d%d%d", &n, &s, &m);
	for (int i = 0; i != n; ++i) {
		scanf("%d", v + i);
	}
	printf("%d", f(0, s));
}
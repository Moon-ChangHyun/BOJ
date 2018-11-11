#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, hi = 0, lo = 0;
vector<int> h;

bool cutting(int k) {
	long long s = 0;
	for (int i = 0; i != n; ++i) {
		int dif = h[i] - k;
		if (dif > 0)
			s += dif;
	}
	return s >= m;
}

int main() {
	scanf("%d%d", &n, &m);
	h.resize(n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &h[i]);
		hi = max(hi, h[i]);
	}
	int mid = hi >> 1;
	while (hi != lo + 1) {
		if (cutting(mid))
			lo = mid;
		else
			hi = mid;
		mid = ((lo + hi) >> 1);
	}
	printf("%d", lo);
}
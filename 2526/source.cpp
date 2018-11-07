#include <cstdio>
int main() {
	int n, p, arr[97];
	scanf("%d%d", &n, &p);
	for (int i = 0; i != p; ++i) arr[i] = -1;
	int t = (n*n) % p;
	while (arr[t] == -1) {
		arr[t] = (t * n) % p;
		t = arr[t];
	}
	int k = t, ret = 1;
	t = arr[t];
	while (k != t) {
		++ret;
		t = arr[t];
	}
	printf("%d", ret);
}
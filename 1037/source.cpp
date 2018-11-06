#include<cstdio>
int main() {
	int n, x, mn = 1000001, mx = 1;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &x);
		mn = x < mn ? x : mn;
		mx = x > mx ? x : mx;
	}
	printf("%d", mn*mx);
}
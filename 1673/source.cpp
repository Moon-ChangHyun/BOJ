#include<cstdio>
int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		int ret = n;
		int stamp = n;
		while (stamp >= k) {
			int add = stamp / k;
			stamp %= k;
			stamp += add;
			ret += add;
		}
		printf("%d\n", ret);
	}
}
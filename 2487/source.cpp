#include<cstdio>
int n, k, arr[20001];
long long ret = 1, cnt;
bool visit[20001];
long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		arr[k] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			cnt = 1;
			k = arr[i];
			while (i != k) {
				visit[k] = true;
				k = arr[k];
				++cnt;
			}
			if (ret < cnt) {
				ret ^= cnt;
				cnt ^= ret;
				ret ^= cnt;
			}
			ret = ret * cnt / gcd(ret, cnt);
		}
	}
	printf("%lld", ret);
}
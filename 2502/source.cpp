#include<cstdio>
int main() {
	int d, k;
	int a1[30] = { 1, 0 }, a2[30] = { 0, 1 };
	for (int i = 2; i != 30; ++i) {
		a1[i] = a1[i - 1] + a1[i - 2];
		a2[i] = a2[i - 1] + a2[i - 2];
	}
	scanf("%d%d", &d, &k);
	for (int i = 1; ; ++i) {
		if (!((k - a1[d - 1] * i) % a2[d - 1])) {
			printf("%d\n%d", i, (k - a1[d - 1] * i) / a2[d - 1]);
			break;
		}
	}
}
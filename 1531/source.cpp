#include<cstdio>
int arr[100][100];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i != n; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for (int j = b - 1; j != d; ++j) {
			for (int k = a - 1; k != c; ++k) {
				++arr[j][k];
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i != 100; ++i) {
		for (int j = 0; j != 100; ++j) {
			if (arr[i][j] > m)
				++cnt;
		}
	}
	printf("%d", cnt);
}
#include<cstdio>
int arr[15][15];
int main() {
	for (int j = 0; j != 15; ++j)
		arr[0][j] = j;
	for (int i = 1; i != 15; ++i) {
		arr[i][0] = 0;
		for (int j = 1; j != 15; ++j)
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
	}
	int T;
	for (scanf("%d", &T); ~--T;) {
		int k, n;
		scanf("%d%d", &k, &n);
		printf("%d\n", arr[k][n]);
	}
}
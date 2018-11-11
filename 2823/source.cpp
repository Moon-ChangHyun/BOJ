#include<cstdio>
int main() {
	char arr[10][10];
	int R, C;
	bool ret = false;
	scanf("%d%d", &R, &C);
	for (int i = 0; i != R; ++i)
		for (int j = 0; j != C; ++j)
			scanf(" %c", &arr[i][j]);
	for (int i = 0; i != R; ++i) {
		for (int j = 0; j != C; ++j) {
			if (arr[i][j] == '.') {
				int cnt = 0;
				if (i && arr[i - 1][j] == '.') ++cnt;
				if (j && arr[i][j - 1] == '.') ++cnt;
				if (i < R - 1 && arr[i + 1][j] == '.') ++cnt;
				if (j < C - 1 && arr[i][j + 1] == '.') ++cnt;
				if (cnt < 2) ret = true;
			}
		}
	}
	printf("%d", ret);
}
// 1660ms, 1196KB

#include <cstdio>
int c[102][102], f[102][102], rN, cN, S, st[100], top;
int main() {
	scanf("%d", &rN);
	cN = rN + 50;
	for (int i = 1; i <= rN; ++i) {
		scanf("%d", &c[0][i]);
		S += c[0][i];
	}
	for (int i = 51; i <= cN; ++i)
		scanf("%d", &c[i][101]);
	while (S) {
		for (int i = 1; i <= rN; ++i)
			for (int j = 51; j <= cN; ++j)
				++c[i][j];
		while (true) {
			int p[102];
			for (int& k : p)
				k = -1;
			p[0] = 0;
			top = 0;
			st[top] = 0;
			while (top >= 0 && p[101] == -1) {
				int i = st[top--];
				for (int j = 0; j != 102; ++j)
					if (c[i][j] - f[i][j] > 0 && p[j] == -1) {
						st[++top] = j;
						p[j] = i;
					}
			}
			if (p[101] == -1)
				break;
			for (int i = 101; i; i = p[i]) {
				f[p[i]][i] += 1;
				f[i][p[i]] -= 1;
			}
			--S;
		}
	}
	printf("%d\n", c[1][51]);
	for (int i = 1; i <= rN; ++i) {
		for (int j = 51; j <= cN; ++j)
			printf("%d ", f[i][j]);
		printf("\n");
	}
}
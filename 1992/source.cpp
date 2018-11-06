#include<cstdio>
bool v[64][64];
int i, j;
void f(int y, int x, int size) {
	bool first = v[y][x];
	bool same = true;
	for (i = y; i != y + size; ++i) {
		for (j = x; j != x + size; ++j) {
			if (first ^ v[i][j]) {
				same = false;
				break;
			}
		}
	}
	if (same) {
		putchar(first + '0');
		return;
	}
	putchar('(');
	f(y, x, size / 2);
	f(y, x + size / 2, size / 2);
	f(y + size / 2, x, size / 2);
	f(y + size / 2, x + size / 2, size / 2);
	putchar(')');
}
int main() {
	int n;
	char t;
	scanf("%d", &n);
	for (i = 0; i != n; ++i) {
		for (j = 0; j != n; ++j) {
			scanf(" %c", &t);
			v[i][j] = t == '1' ? 1 : 0;
		}
	}
	f(0, 0, n);
}
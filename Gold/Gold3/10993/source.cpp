// 124ms, 3000KB

#include<cstdio>
#include<cmath>
bool arr[1023][2045];

void f(int y, int x, int s) {
	if (s == 1) {
		arr[y][x] = true;
		return;
	}
	int maxCol = x + pow(2, s + 1) - 4;
	for (int j = x; j <= maxCol; ++j)
		arr[y][j] = true;
	if (s % 2) {
		int minRow = y - pow(2, s) + 2;
		for (int i = y - 1, k = 1; i >= minRow; --i, ++k) {
			arr[i][x + k] = true;
			arr[i][maxCol - k] = true;
		}
		f(y - pow(2, s - 1) + 1, x + pow(2, s - 1), s - 1);
	}
	else {
		int maxRow = y + pow(2, s) - 2;
		for (int i = y + 1, k = 1; i <= maxRow; ++i, ++k) {
			arr[i][x + k] = true;
			arr[i][maxCol - k] = true;
		}
		f(y + pow(2, s - 1) - 1, x + pow(2, s - 1), s - 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	if (n % 2) {
		f(pow(2, n) - 2, 0, n);
		for (int i = 0; i < pow(2, n) - 1; ++i) {
			for (int j = 0; j < pow(2, n) - 1 + i; ++j)
				printf("%c", arr[i][j] ? '*' : ' ');
			printf("\n");
		}
	}
	else {
		f(0, 0, n);
		for (int i = 0; i < pow(2, n) - 1; ++i) {
			for (int j = 0; j < pow(2, n + 1) - 3 - i; ++j)
				printf("%c", arr[i][j] ? '*' : ' ');
			printf("\n");
		}
	}
}
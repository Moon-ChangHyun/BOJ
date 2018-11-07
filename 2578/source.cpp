#include<cstdio>
bool check[5][5];
int board[5][5];
int main() {
	for (int i = 0; i != 5; ++i)
		for (int j = 0; j != 5; ++j) {
			int x;
			scanf("%d", &x);
			board[x / 5][x % 5] = i * 5 + j;
		}
	int line = 0;
	for (int i = 0; i != 25; ++i) {
		int x;
		scanf("%d", &x);
		int pos = board[x / 5][x % 5];
		int row = pos / 5;
		int col = pos % 5;
		check[row][col] = true;
		bool tmpB = true;
		for (int k = 0; k != 5; ++k)
			tmpB &= check[k][col];
		if (tmpB) ++line;
		tmpB = true;
		for (int k = 0; k != 5; ++k)
			tmpB &= check[row][k];
		if (tmpB) ++line;
		if (row + col == 4) {
			tmpB = true;
			for (int k = 0; k != 5; ++k)
				tmpB &= check[k][4 - k];
			if (tmpB) ++line;
		}
		if (row == col) {
			tmpB = true;
			for (int k = 0; k != 5; ++k)
				tmpB &= check[k][k];
			if (tmpB) ++line;
		}
		if (line >= 3) {
			printf("%d", i + 1);
			break;
		}
	}
}
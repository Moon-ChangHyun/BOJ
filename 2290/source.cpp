#include<cstdio>
#include<vector>
#include<array>
using namespace std;

int main() {
	int s;
	char str[11];
	scanf("%d%s", &s, str);
	array<vector<vector<char>>, 10> number;
	number.fill(vector<vector<char>>(2 * s + 3, vector<char>(s + 2, ' ')));
	for (int k = 0; k <= 9; ++k) {
		if (k == 1 || k == 4 || k == 7) continue;
		for (int j = 1; j < s + 1; ++j)
			number[k][0][j] = number[k][2 * s + 2][j] = '-';
	}
	for (int k = 2; k <= 9; ++k) {
		if (k == 7) continue;
		for (int j = 1; j < s + 1; ++j)
			number[k][s + 1][j] = '-';
	}
	for (int j = 1; j < s + 1; ++j)
		number[7][0][j] = '-';
	for (int k = 0; k <= 9; ++k) {
		if (k == 2 || k == 5 || k == 6) continue;
		for (int i = 1; i < 2 * s + 2; ++i) {
			if (i == s + 1) continue;
			number[k][i][s + 1] = '|';
		}
	}
	for (int i = 1; i < s + 1; ++i) {
		number[2][i][s + 1] = '|';
		number[0][i][0] = number[4][i][0] = number[5][i][0] = number[6][i][0] = number[8][i][0] = number[9][i][0] = '|';
	}
	for (int i = s + 2; i < 2 * s + 2; ++i) {
		number[5][i][s + 1] = number[6][i][s + 1] = '|';
		number[0][i][0] = number[2][i][0] = number[6][i][0] = number[8][i][0] = '|';
	}
	for (int i = 0; i < 2 * s + 3; ++i) {
		for (int k = 0; str[k]; ++k) {
			for (int j = 0; j < s + 2; ++j)
				putchar(number[str[k] & 0xf][i][j]);
			putchar(' ');
		}
		putchar('\n');
	}
}
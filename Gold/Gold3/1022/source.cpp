// 0ms, 2020KB

#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int getVal(int r, int c) {
	int k = max(abs(r), abs(c));
	if (k == 0) return 1;
	int num = 1 + ((k * (k - 1)) << 2);
	if (c == k) {
		if (r == k)
			return num + (k << 3);
		return num + k - r;
	}
	if (r == -k)
		return num + (k << 1) + k - c;
	if (c == -k)
		return num + (k << 2) + r + k;
	return num + 6 * k + c + k;
}

int main() {
	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	vector<vector<int>> board(r2 - r1 + 1, vector<int>(c2 - c1 + 1));

	int maxNum = 0;
	int biasY = -r1, biasX = -c1;
	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			auto& val = board[i + biasY][j + biasX];
			val = getVal(i, j);
			maxNum = max(maxNum, val);
		}
	}

	int width = 0;
	while (maxNum) {
		maxNum /= 10;
		++width;
	}

	for (auto& row : board) {
		for (auto x : row) {
			cout << setw(width) << x << ' ';
		}
		cout << '\n';
	}
}
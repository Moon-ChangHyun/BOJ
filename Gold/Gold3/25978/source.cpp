// 292ms, 17792KB

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<ll>> board(n + 2, vector<ll>(n + 2));
	vector<vector<ll>> change(n + 2, vector<ll>(n + 2));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}
	int type, i1, j1, i2, j2, queryNum = 0;
	for (;;) {
		++queryNum;
		int k;
		cin >> type >> i1 >> j1 >> i2 >> j2;
		if (type == 2)
			break;
		cin >> k;
		++i1; ++j1; i2 += 2; j2 += 2;
		change[i1][j1] += k;
		change[i1][j2] -= k;
		change[i2][j1] -= k;
		change[i2][j2] += k;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			change[i][j] += change[i - 1][j] + change[i][j - 1] - change[i - 1][j - 1];
			board[i][j] += change[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			board[i][j] += board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1];
		}
	}
	++i2; ++j2;
	cout << board[i2][j2] - board[i1][j2] - board[i2][j1] + board[i1][j1] << '\n';
	for (int i = queryNum; i < m; ++i) {
		cin >> type >> i1 >> j1 >> i2 >> j2;
		++i2; ++j2;
		cout << board[i2][j2] - board[i1][j2] - board[i2][j1] + board[i1][j1] << '\n';
	}
}
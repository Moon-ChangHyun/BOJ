// 128ms, 34644KB

#include<vector>
#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<char>> board(n + 1, vector<char>(n + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}

	vector<vector<int>> 
		cntRowAA(n + 1, vector<int>(n + 1)), cntColAA(n + 1, vector<int>(n + 1)),
		cntRowAB(n + 1, vector<int>(n + 1)), cntColAB(n + 1, vector<int>(n + 1)),
		cntRowBA(n + 1, vector<int>(n + 1)), cntColBA(n + 1, vector<int>(n + 1)),
		cntRowBB(n + 1, vector<int>(n + 1)), cntColBB(n + 1, vector<int>(n + 1));
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cntRowAA[i][j] = cntRowAA[i - 1][j] + cntRowAA[i][j - 1] - cntRowAA[i - 1][j - 1];
			cntColAA[i][j] = cntColAA[i - 1][j] + cntColAA[i][j - 1] - cntColAA[i - 1][j - 1];
			cntRowAB[i][j] = cntRowAB[i - 1][j] + cntRowAB[i][j - 1] - cntRowAB[i - 1][j - 1];
			cntColAB[i][j] = cntColAB[i - 1][j] + cntColAB[i][j - 1] - cntColAB[i - 1][j - 1];
			cntRowBA[i][j] = cntRowBA[i - 1][j] + cntRowBA[i][j - 1] - cntRowBA[i - 1][j - 1];
			cntColBA[i][j] = cntColBA[i - 1][j] + cntColBA[i][j - 1] - cntColBA[i - 1][j - 1];
			cntRowBB[i][j] = cntRowBB[i - 1][j] + cntRowBB[i][j - 1] - cntRowBB[i - 1][j - 1];
			cntColBB[i][j] = cntColBB[i - 1][j] + cntColBB[i][j - 1] - cntColBB[i - 1][j - 1];
			if (board[i][j] == 'a') {
				cntRowAA[i][j] += (board[i][j - 1] == 'a');
				cntColAA[i][j] += (board[i - 1][j] == 'a');
				cntRowBA[i][j] += (board[i][j - 1] == 'b');
				cntColBA[i][j] += (board[i - 1][j] == 'b');
			}
			else {
				cntRowAB[i][j] += (board[i][j - 1] == 'a');
				cntColAB[i][j] += (board[i - 1][j] == 'a');
				cntRowBB[i][j] += (board[i][j - 1] == 'b');
				cntColBB[i][j] += (board[i - 1][j] == 'b');
			}
		}
	}

	int q;
	for (cin >> q; ~--q; ) {
		int i1, j1, i2, j2, ans;
		string s;
		cin >> i1 >> j1 >> i2 >> j2 >> s;
		if (s[0] == 'a') {
			if (s[1] == 'a') {
				ans = cntColAA[i2][j2] - cntColAA[i1][j2] - cntColAA[i2][j1 - 1] + cntColAA[i1][j1 - 1];
				ans += cntRowAA[i2][j2] - cntRowAA[i1 - 1][j2] - cntRowAA[i2][j1] + cntRowAA[i1 - 1][j1];
			}
			else {
				ans = cntColAB[i2][j2] - cntColAB[i1][j2] - cntColAB[i2][j1 - 1] + cntColAB[i1][j1 - 1];
				ans += cntRowAB[i2][j2] - cntRowAB[i1 - 1][j2] - cntRowAB[i2][j1] + cntRowAB[i1 - 1][j1];
			}
		}
		else {
			if (s[1] == 'a') {
				ans = cntColBA[i2][j2] - cntColBA[i1][j2] - cntColBA[i2][j1 - 1] + cntColBA[i1][j1 - 1];
				ans += cntRowBA[i2][j2] - cntRowBA[i1 - 1][j2] - cntRowBA[i2][j1] + cntRowBA[i1 - 1][j1];
			}
			else {
				ans = cntColBB[i2][j2] - cntColBB[i1][j2] - cntColBB[i2][j1 - 1] + cntColBB[i1][j1 - 1];
				ans += cntRowBB[i2][j2] - cntRowBB[i1 - 1][j2] - cntRowBB[i2][j1] + cntRowBB[i1 - 1][j1];
			}
		}
		cout << ans << '\n';
	}
}
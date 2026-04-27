// 352ms, 1696KB

#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<vector<pair<int, int>>> bridgeTerminal;
vector<vector<char>> board;
void dfs(int y, int x, vector<pair<int, int>>& bt) {
	if (y < 0 || y >= N || x < 0 || x >= N) return;
	if (board[y][x] == '0') {
		board[y][x] = 0;
		bt.emplace_back(y, x);
	}
	else if (board[y][x] == '1') {
		board[y][x] = 0;
		dfs(y - 1, x, bt);
		dfs(y + 1, x, bt);
		dfs(y, x - 1, bt);
		dfs(y, x + 1, bt);
	}
}
int main() {
	scanf("%d", &N);
	board.resize(N, vector<char>(N));
	for (int i = 0; i != N; ++i)
		for (int j = 0; j != N; ++j)
			scanf(" %c", &board[i][j]);
	for(int i = 0; i != N; ++i)
		for(int j = 0; j != N; ++j)
			if (board[i][j] == '1') {
				vector<pair<int, int>> tmp;
				dfs(i, j, tmp);
				for (auto& it : tmp)
					board[it.first][it.second] = '0';
				bridgeTerminal.push_back(move(tmp));
			}
	int ret = 987654321;
	for (int i = 0; i < bridgeTerminal.size(); ++i) {
		for (int j = i + 1; j < bridgeTerminal.size(); ++j) {
			for (auto& a: bridgeTerminal[i]) {
				for (auto& b : bridgeTerminal[j]) {
					ret = min(ret, abs(a.first - b.first) + abs(a.second - b.second) + 1);
				}
			}
		}
	}
	printf("%d", ret);
}
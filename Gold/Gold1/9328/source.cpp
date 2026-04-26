// 8ms, 1724KB

#include<cstdio>
#include<vector>
using namespace std;
int H, W;
vector<vector<char>> board;
vector<vector<bool>> visit;
vector<vector<pair<int, int>>> doorPos;
vector<bool> keyOwned;

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int dfs(int y, int x) {
	if (x < 0 || y < 0 || x >= W || y >= H || visit[y][x] || board[y][x] == '*') return 0;
	visit[y][x] = true;
	int ret = 0;
	if (board[y][x] >= 'a') {
		keyOwned[board[y][x] - 'a'] = true;
	}
	else if (board[y][x] >= 'A') {
		if (!keyOwned[board[y][x] - 'A']) {
			doorPos[board[y][x] - 'A'].push_back({ y, x });
			return 0;
		}
	}
	else if(board[y][x] == '$'){
		++ret;
	}
	for (int k = 0; k != 4; ++k) {
		ret += dfs(y + dy[k], x + dx[k]);
	}
	return ret;
}

int solve() {
	int ret = 0;
	for (int i = 0; i < H; ++i) {
		ret += dfs(i, 0);
		ret += dfs(i, W - 1);
	}
	for (int j = 0; j < W; ++j) {
		ret += dfs(0, j);
		ret += dfs(H - 1, j);
	}
	vector<pair<int, int>> sp;
	do {
		sp.clear();
		for (int k = 0; k != 26; ++k) {
			if (keyOwned[k]) {
				sp.insert(sp.end(), doorPos[k].begin(), doorPos[k].end());
				doorPos[k].clear();
			}
		}
		for (auto& pos : sp)
			visit[pos.first][pos.second] = false;
		for(auto& pos : sp)
			ret += dfs(pos.first, pos.second);
	} while (!sp.empty());
	return ret;
}

int main() {
	int T;
	for (scanf("%d", &T); ~--T; ) {
		scanf("%d%d", &H, &W);
		board = vector<vector<char>>(H, vector<char>(W));
		visit = vector<vector<bool>>(H, vector<bool>(W, false));
		doorPos = vector<vector<pair<int, int>>>(26, vector<pair<int, int>>());
		keyOwned = vector<bool>(26, false);
		for (int i = 0; i != H; ++i) {
			for (int j = 0; j != W; ++j) {
				scanf(" %c", &board[i][j]);
			}
		}
		char tmp[27];
		scanf(" %s", tmp);
		if (tmp[0] != '0')
			for (int i = 0; tmp[i]; ++i)
				keyOwned[tmp[i] - 'a'] = true;
		printf("%d\n", solve());
	}
}
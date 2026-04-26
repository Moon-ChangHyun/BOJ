// 4ms, 1228KB

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> tilting(int dir, vector<vector<int>>& board) {
	vector<vector<int>> ret(board.size(), vector<int>(board.size()));
	switch (dir) {
	case 0: //up
		for (int j = 0; j < board.size(); ++j) {
			vector<int> vals;
			vals.reserve(board.size());
			bool updated = false;
			for (int i = 0; i < board.size(); ++i) {
				if (board[i][j] == 0) continue;
				if (!vals.empty() && vals.back() == board[i][j] && !updated) {
					vals.back() <<= 1;
					updated = true;
				}
				else {
					vals.push_back(board[i][j]);
					updated = false;
				}
			}
			for (int i = 0; i < vals.size(); ++i)
				ret[i][j] = vals[i];
		}
		break;
	case 1: //down
		for (int j = 0; j < board.size(); ++j) {
			vector<int> vals;
			vals.reserve(board.size());
			bool updated = false;
			for (int i = board.size(); --i >= 0;) {
				if (board[i][j] == 0) continue;
				if (!vals.empty() && vals.back() == board[i][j] && !updated) {
					vals.back() <<= 1;
					updated = true;
				}
				else {
					vals.push_back(board[i][j]);
					updated = false;
				}
			}
			for(int valIdx = 0; valIdx < vals.size(); ++valIdx)
				ret[board.size() - 1 - valIdx][j] = vals[valIdx];
		}
		break;
	case 2: //left
		for (int i = 0; i < board.size(); ++i) {
			vector<int> vals;
			vals.reserve(board.size());
			bool updated = false;
			for (int j = 0; j < board.size(); ++j) {
				if (board[i][j] == 0) continue;
				if (!vals.empty() && vals.back() == board[i][j] && !updated) {
					vals.back() <<= 1;
					updated = true;
				}
				else {
					vals.push_back(board[i][j]);
					updated = false;
				}
			}
			for (int j = 0; j < vals.size(); ++j)
				ret[i][j] = vals[j];
		}
		break;
	case 3: //right
		for (int i = 0; i < board.size(); ++i) {
			vector<int> vals;
			vals.reserve(board.size());
			bool updated = false;
			for (int j = board.size(); --j >= 0;) {
				if (board[i][j] == 0) continue;
				if (!vals.empty() && vals.back() == board[i][j] && !updated) {
					vals.back() <<= 1;
					updated = true;
				}
				else {
					vals.push_back(board[i][j]);
					updated = false;
				}
			}
			for (int valIdx = 0; valIdx < vals.size(); ++valIdx)
				ret[i][board.size() - 1 - valIdx] = vals[valIdx];
		}
	}
	return ret;
}

int dfs(int depth, vector<vector<int>> board) {
	int ret = 0;
	if (depth == 0) {
		for (auto& row : board)
			for (auto cell : row)
				ret = max(ret, cell);
		return ret;
	}
	for (int i = 0; i != 4; ++i) {
		ret = max(ret, dfs(depth - 1, tilting(i, board)));
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			scanf("%d", &board[i][j]);
	printf("%d", dfs(5, board));
}
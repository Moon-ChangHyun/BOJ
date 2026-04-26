// 128ms, 27576KB

#include<iostream>
#include<vector>
#include<set>
using namespace std;
int N, M, cnt[500001], lastComp = 1;
char board[1000][1000];
vector<vector<int>> compNum;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int dfs(int y, int x) {
	if (board[y][x] == '1' || compNum[y][x]) return 0;
	compNum[y][x] = lastComp;
	int ret = 1;
	for (int k = 0; k != 4; ++k) {
		int nextY = y + dy[k];
		int nextX = x + dx[k];
		if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M)
			ret += dfs(nextY, nextX);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	compNum.resize(N, vector<int>(M, 0));
	for (int i = 0; i != N; ++i) {
		cin >> board[i];
	}
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != M; ++j) {
			int sz = dfs(i, j);
			if (sz != 0) {
				cnt[lastComp++] = sz;
			}
		}
	}
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != M; ++j) {
			if (board[i][j] == '1') {
				int sum = 1;
				set<int> compSet;
				for (int k = 0; k != 4; ++k) {
					int nextY = i + dy[k];
					int nextX = j + dx[k];
					if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
						compSet.insert(compNum[nextY][nextX]);
					}
				}
				for (auto it : compSet)
					sum += cnt[it];
				cout << sum % 10;
			}
			else {
				cout << '0';
			}
		}
		cout << '\n';
	}
}
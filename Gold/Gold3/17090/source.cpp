// 8ms, 7136KB

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N, M;
vector<string> board;
vector<vector<int>> dp; //0 미정, 1 가능, 2 불가

int process(int y, int x) {
	int& ret = dp[y][x];
	ret = 2;
	int ny = y, nx = x;
	switch (board[y][x]) {
	case 'U':
		--ny;
		break;
	case 'R':
		++nx;
		break;
	case 'D':
		++ny;
		break;
	case 'L':
		--nx;
		break;
	}
	if (ny < 0 || nx < 0 || ny >= N || nx >= M) return ret = 1;
	if (dp[ny][nx])
		return ret = dp[ny][nx];
	return ret = process(ny, nx);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	board.resize(N);
	dp.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (dp[i][j] == 0)
				process(i, j);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (dp[i][j] == 1)
				++ans;
	cout << ans;
}
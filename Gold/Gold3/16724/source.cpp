// 84ms, 2424KB

#include<cstdio>
#include<vector>
using namespace std;
int N, M;
vector<vector<bool>> visit;
vector<vector<char>> board;
void dfs(int y, int x) {
	visit[y][x] = true;
	switch (board[y][x]) {
	case 'U':
		if(!visit[y - 1][x])
			dfs(y - 1, x);
		break;
	case 'D':
		if(!visit[y + 1][x])
			dfs(y + 1, x);
		break;
	case 'L':
		if(!visit[y][x - 1])
			dfs(y, x - 1);
		break;
	case 'R':
		if(!visit[y][x + 1])
			dfs(y, x + 1);
	}
	if (y > 0 && !visit[y - 1][x] && board[y - 1][x] == 'D')
		dfs(y - 1, x);
	if (y < N - 1 && !visit[y + 1][x] && board[y + 1][x] == 'U')
		dfs(y + 1, x);
	if (x > 0 && !visit[y][x - 1] && board[y][x - 1] == 'R')
		dfs(y, x - 1);
	if (x < M - 1 && !visit[y][x + 1] && board[y][x + 1] == 'L')
		dfs(y, x + 1);
}

int main() {
	scanf("%d%d", &N, &M);
	visit.resize(N, vector<bool>(M, false));
	board.resize(N, vector<char>(M));
	int ret = 0;
	for (int i = 0; i != N; ++i)
		for (int j = 0; j != M; ++j)
			scanf(" %c", &board[i][j]);
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != M; ++j) {
			if (!visit[i][j]) {
				dfs(i, j);
				++ret;
			}
		}
	}
	printf("%d", ret);
}
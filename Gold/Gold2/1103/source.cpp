// 0ms, 1304KB

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

constexpr int INF = 987654321;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N, M;
vector<vector<char>> board;
vector<vector<bool>> visit;
vector<vector<int>> dp;

int func(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M || board[y][x] == 'H')
		return 0;
	if (visit[y][x])
		return INF;
	int& ret = dp[y][x];
	if (ret)
		return ret;
	visit[y][x] = true;
	int val = board[y][x] & 0xf;
	for (int k = 0; k < 4; ++k)
	{
		int ny = y + val * dy[k], nx = x + val * dx[k];
		ret = max(ret, func(ny, nx));
	}
	visit[y][x] = false;
	if (ret < INF)
		++ret;
	return ret;
}


int main()
{
	scanf("%d%d", &N, &M);
	board.resize(N, vector<char>(M));
	visit.resize(N, vector<bool>(M));
	dp.resize(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf(" %c", &board[i][j]);

	auto ret = func(0, 0);
	if (ret == INF)
		printf("-1");
	else
		printf("%d", ret);
}
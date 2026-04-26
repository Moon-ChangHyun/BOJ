// 0ms, 1896KB

#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
constexpr int INF = 987654321;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	vector<vector<char>> map(N, vector<char>(M));
	vector<pair<int, int>> dst;
	dst.reserve(2);
	int sY, sX;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S')
				sY = i, sX = j;
			else if (map[i][j] == 'C')
				dst.emplace_back(i, j);
		}
	}
	
	//y,x,dir,flag
	vector<vector<vector<vector<int>>>> dist (N, vector<vector<vector<int>>>(M, vector<vector<int>>(4, vector<int>(4, INF))));
	queue<pair<int, int>> qP;
	queue<int> qDir;
	queue<int> qFlag;

	for (int k = 0; k < 4; ++k)
	{
		dist[sY][sX][k][0] = 0;
		qP.emplace(sY, sX);
		qDir.push(k);
		qFlag.push(0);
	}
	
	while (!qP.empty())
	{
		int y = qP.front().first, x = qP.front().second; qP.pop();
		int dir = qDir.front(); qDir.pop();
		int flag = qFlag.front(); qFlag.pop();
		if (flag == 3)
		{
			printf("%d", dist[y][x][dir][flag]);
			return 0;
		}
		for (int k = 0; k < 4; ++k)
		{
			if (dir == k) continue;
			int ny = y + dy[k], nx = x + dx[k];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == '#') continue;
			int nFlag = flag;
			if (ny == dst[0].first && nx == dst[0].second)
				nFlag |= 1;
			else if (ny == dst[1].first && nx == dst[1].second)
				nFlag |= 2;
			if (dist[ny][nx][k][nFlag] < INF) continue;
			dist[ny][nx][k][nFlag] = dist[y][x][dir][flag] + 1;
			qP.emplace(ny, nx);
			qDir.push(k);
			qFlag.push(nFlag);
		}
	}
	printf("-1");
}
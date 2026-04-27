// 0ms, 2292KB

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
constexpr int INF = 987654;

const int dy[4]{ 0, 0, 1, -1 };
const int dx[4]{ 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	int M, N;
	cin >> M >> N;
	vector<vector<int>> map(M, vector<int>(N));
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];
	int sY, sX, sD, dstY, dstX, dstD;
	cin >> sY >> sX >> sD >> dstY >> dstX >> dstD;
	--sY; --sX; --sD;
	--dstY; --dstX; --dstD;
	vector<vector<vector<int>>> dist(M, vector<vector<int>>(N, vector<int>(4, INF)));
	queue<int> qX, qY, qD;
	qX.push(sX);
	qY.push(sY);
	qD.push(sD);
	dist[sY][sX][sD] = 0;
	while (!qX.empty())
	{
		int x = qX.front(); qX.pop();
		int y = qY.front(); qY.pop();
		int dir = qD.front(); qD.pop();
		
		for (int k = 1; k <= 3; ++k)
		{
			int nextX = x + dx[dir] * k;
			int nextY = y + dy[dir] * k;
			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M || dist[nextY][nextX][dir] != INF)
				continue;
			if (map[nextY][nextX] == 1)
				break;
			qX.push(nextX);
			qY.push(nextY);
			qD.push(dir);
			dist[nextY][nextX][dir] = dist[y][x][dir] + 1;
		}

		if (dir < 2)
		{
			if (dist[y][x][2] == INF)
			{
				qX.push(x);
				qY.push(y);
				qD.push(2);
				dist[y][x][2] = dist[y][x][dir] + 1;
			}
			if (dist[y][x][3] == INF)
			{
				qX.push(x);
				qY.push(y);
				qD.push(3);
				dist[y][x][3] = dist[y][x][dir] + 1;
			}
		}
		else
		{
			if (dist[y][x][0] == INF)
			{
				qX.push(x);
				qY.push(y);
				qD.push(0);
				dist[y][x][0] = dist[y][x][dir] + 1;
			}
			if (dist[y][x][1] == INF)
			{
				qX.push(x);
				qY.push(y);
				qD.push(1);
				dist[y][x][1] = dist[y][x][dir] + 1;
			}
		}
	}
	cout << dist[dstY][dstX][dstD];
}
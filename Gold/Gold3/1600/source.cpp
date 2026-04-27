// 100ms, 7308KB

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

constexpr int INF = 987654321;
const int dy[12] = { -1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2 };
const int dx[12] = { 0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1 };

int main()
{
	ios::sync_with_stdio(false);
	int K, W, H;
	cin >> K >> W >> H;
	vector<vector<bool>> map(H, vector<bool>(W));
	vector<vector<vector<int>>> dist(K + 1, vector<vector<int>>(H, vector<int>(W, INF)));

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			int x;
			cin >> x;
			map[i][j] = x == 1;
		}
	}

	queue<int> yQ, xQ, kQ;
	yQ.push(0); xQ.push(0); kQ.push(K);
	dist[K][0][0] = 0;

	while (!yQ.empty())
	{
		int y = yQ.front(); yQ.pop();
		int x = xQ.front(); xQ.pop();
		int k = kQ.front(); kQ.pop();

		if (y == H - 1 && x == W - 1)
		{
			cout << dist[k][y][x];
			return 0;
		}

		for (int dir = 0; dir < 4; ++dir)
		{
			int ny = y + dy[dir], nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx] || dist[k][ny][nx] <= dist[k][y][x] + 1)
				continue;
			yQ.push(ny); xQ.push(nx); kQ.push(k);
			dist[k][ny][nx] = dist[k][y][x] + 1;
		}
		if (k > 0)
		{
			for (int dir = 4; dir < 12; ++dir)
			{
				int ny = y + dy[dir], nx = x + dx[dir];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx] || dist[k - 1][ny][nx] <= dist[k][y][x] + 1)
					continue;
				yQ.push(ny); xQ.push(nx); kQ.push(k - 1);
				dist[k - 1][ny][nx] = dist[k][y][x] + 1;
			}
		}
	}
	cout << -1;
}
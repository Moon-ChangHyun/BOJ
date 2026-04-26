// 24ms, 3348KB

#include<iostream>
#include<deque>
#include<vector>

using namespace std;

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<char>> map(N, vector<char>(M));
	int s, f;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
				s = i * M + j;
			else if (map[i][j] == 'F')
				f = i * M + j;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 'g')
			{
				for (int k = 0; k < 4; ++k)
				{
					int y = i + dy[k], x = j + dx[k];
					if (y < 0 || x < 0 || y >= N || x >= M) continue;
					if (map[y][x] == '.')
						map[y][x] = 'w';
				}
			}
		}
	}

	deque<int> dqNode;
	deque<pair<int, int>> dqDist;
	dqNode.push_back(s);
	dqDist.emplace_back(0, 0);
	vector<pair<int, int>> dist(N * M, {9999,9999});//쓰레기수, 옆으로지나간수 최소값
	while (!dqNode.empty())
	{
		int nd = dqNode.front(); dqNode.pop_front();
		auto curDist = dqDist.front(); dqDist.pop_front();
		int y = nd / M, x = nd % M;

		if (curDist.first == dist[nd].first && curDist.second > dist[nd].second)
			continue;

		if (nd == f && curDist.first > dist[nd].first)
			break;

		for (int k = 0; k < 4; ++k)
		{
			int ny = y + dy[k], nx = x + dx[k];
			int nextNd = ny * M + nx;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			auto nextDist = curDist;
			if (map[ny][nx] == 'g')
			{
				nextDist.first += 1;
				if (dist[nextNd] > nextDist)
				{
					dist[nextNd] = nextDist;
					dqNode.push_back(nextNd);
					dqDist.push_back(nextDist);
				}
			}
			else if (map[ny][nx] == 'w')
			{
				nextDist.second += 1;
				if (dist[nextNd] > nextDist)
				{
					dist[nextNd] = nextDist;
					dqNode.push_front(nextNd);
					dqDist.push_front(nextDist);
				}
			}
			else
			{
				if (dist[nextNd] > nextDist)
				{
					dist[nextNd] = nextDist;
					dqNode.push_front(nextNd);
					dqDist.push_front(nextDist);
				}
			}
		}
	}
	cout << dist[f].first << ' ' << dist[f].second;
}
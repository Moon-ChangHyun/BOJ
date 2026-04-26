// 240ms, 22400KB

#include<iostream>
#include<queue>
using namespace std;

int cost[1500][1500];
int dist[1500][1500];
constexpr int INF = 987654321;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(false);

	int R, C, swanIdx = 0;
	pair<int, int> swans[2];
	cin >> R >> C;

	queue<int> q;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			char c;
			cin >> c;
			if (c == 'X')
				cost[i][j] = INF;
			else {
				cost[i][j] = 0;
				if (c == 'L')
					swans[swanIdx++] = { i, j };
				q.push(i * C + j);
			}
		}
	}
	while (!q.empty()) {
		int node = q.front(); q.pop();
		int y = node / C;
		int x = node % C;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C || cost[ny][nx] != INF) continue;
			cost[ny][nx] = cost[y][x] + 1;
			q.push(ny * C + nx);
		}
	}

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			dist[i][j] = INF;

	int start = swans[0].first * C + swans[0].second;
	int end = swans[1].first * C + swans[1].second;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[swans[0].first][swans[0].second] = 0;
	while (!pq.empty()) {
		auto node = pq.top(); pq.pop();
		int d = -node.first;
		int y = node.second / C;
		int x = node.second % C;
		if (dist[y][x] < d) continue;
		if (node.second == end) break;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			int nd = max(0, cost[ny][nx] - d);
			if (dist[ny][nx] > d + nd) {
				dist[ny][nx] = d + nd;
				pq.push({ -dist[ny][nx], ny * C + nx });
			}
		}
	}
	int ret = dist[swans[1].first][swans[1].second];
	cout << ret;
}
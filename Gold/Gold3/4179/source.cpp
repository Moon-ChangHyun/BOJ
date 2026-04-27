// 60ms, 11044KB

#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

constexpr int inf = 987654321;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int R, C;
vector<string> map;
vector<vector<int>> fireTime;
vector<vector<int>> dist;

int main() {
	ios::sync_with_stdio(false);
	cin >> R >> C >> ws;
	map.resize(R);
	for (auto& row : map)
		cin >> row;

	fireTime.resize(R, vector<int>(C, inf));
	queue<int> qY, qX, qD;
	int sY, sX;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[i][j] == 'F') {
				fireTime[i][j] = 0;
				qY.push(i);
				qX.push(j);
				qD.push(0);
			}
			else if (map[i][j] == 'J') {
				sY = i;
				sX = j;
			}
		}
	}

	while (!qD.empty()) {
		int y = qY.front(); qY.pop();
		int x = qX.front(); qX.pop();
		int d = qD.front(); qD.pop();

		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C || map[ny][nx] == '#' || fireTime[ny][nx] != inf)
				continue;
			fireTime[ny][nx] = d + 1;
			qY.push(ny);
			qX.push(nx);
			qD.push(d + 1);
		}
	}

	dist.resize(R, vector<int>(C, inf));
	qY.push(sY);
	qX.push(sX);
	qD.push(0);
	dist[sY][sX] = 0;
	while (!qD.empty()) {
		int y = qY.front(); qY.pop();
		int x = qX.front(); qX.pop();
		int d = qD.front(); qD.pop();

		if (y == 0 || x == 0 || y == R - 1 || x == C - 1) {
			cout << d + 1;
			return 0;
		}

		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C || map[ny][nx] == '#' || dist[ny][nx] != inf)
				continue;
			if (fireTime[ny][nx] <= d + 1)
				continue;
			dist[ny][nx] = d + 1;
			qY.push(ny);
			qX.push(nx);
			qD.push(d + 1);
		}
	}
	cout << "IMPOSSIBLE";
}
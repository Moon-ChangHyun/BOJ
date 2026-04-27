// 0ms, 1228KB

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int N, y, x, sz = 2;
	scanf("%d", &N);
	vector<vector<char>> map(N, vector<char>(N));
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != N; ++j) {
			char val;
			scanf(" %c", &val);
			if (val == '9') {
				y = i; x = j;
				map[i][j] = 0;
			}
			else
				map[i][j] = val & 0xf;
		}
	}
	int ans = 0;
	int cnt = 0;
	while (true) {
		queue<char> qy;
		queue<char> qx;
		vector<vector<int>> dist(N, vector<int>(N, -1));
		qy.push(y);
		qx.push(x);
		dist[y][x] = 0;
		int candNode = -1;
		int shortestDist = 987654321;
		while (!qy.empty()) {
			char cy = qy.front(), cx = qx.front();
			int d = dist[cy][cx];
			qy.pop(); qx.pop();
			if (d > shortestDist)
				break;
			if (map[cy][cx] != 0 && sz > map[cy][cx]) {
				int node = cy * N + cx;
				if (candNode == -1) {
					shortestDist = d;
					candNode = node;
				}
				else if(candNode > node){
					candNode = node;
				}
			}
			static char deltaY[4] = { -1, 0, 0, 1 };
			static char deltaX[4] = { 0, -1, 1, 0 };

			for (int k = 0; k != 4; ++k) {
				char ny = cy + deltaY[k];
				char nx = cx + deltaX[k];
				if (ny >= 0 && nx >= 0 && ny < N && nx < N && dist[ny][nx] == -1 && sz >= map[ny][nx]) {
					qy.push(ny);
					qx.push(nx);
					dist[ny][nx] = d + 1;
				}
			}
		}
		if (candNode == -1)
			break;
		y = candNode / N;
		x = candNode % N;
		map[y][x] = 0;
		if (++cnt == sz) {
			cnt = 0;
			++sz;
		}
		ans += shortestDist;
	}
	printf("%d", ans);
}
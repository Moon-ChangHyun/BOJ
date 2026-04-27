// 92ms, 10776KB

#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
static const int INF = 987654321;
static const int dy[4] = { -1, 0, 1, 0 };
static const int dx[4] = { 0, -1, 0, 1 };
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	vector<vector<char>> map(N, vector<char>(M));
	vector<int> dist[2];
	dist[0].resize(N * M, INF);
	dist[1].resize(N * M, INF);
	for (int i = 0; i != N; ++i)
		for (int j = 0; j != M; ++j)
			scanf(" %c", &map[i][j]);
	queue<int> pos;
	queue<bool> canCrash;
	pos.push(0);
	canCrash.push(true);
	dist[1][0] = 1;
	while (!pos.empty()) {
		int p = pos.front();
		if (p == N * M - 1) break;
		pos.pop();
		int y = p / M;
		int x = p % M;
		bool cc = canCrash.front(); canCrash.pop();

		for (int k = 0; k != 4; ++k) {
			int nextY = y + dy[k];
			int nextX = x + dx[k];
			if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)
				continue;
			int nextP = nextY * M + nextX;
			if (map[nextY][nextX] == '0') {
				if (dist[cc][nextP] == INF) {
					dist[cc][nextP] = dist[cc][p] + 1;
					pos.push(nextP);
					canCrash.push(cc);
				}
			}
			else {
				if (cc && dist[0][nextP] == INF) {
					dist[0][nextP] = dist[cc][p] + 1;
					pos.push(nextP);
					canCrash.push(false);
				}
			}
		}
	}
	if (pos.empty())
		printf("-1");
	else
		printf("%d", min(dist[0][N * M - 1], dist[1][N * M - 1]));
}
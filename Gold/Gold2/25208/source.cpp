// 72ms, 8396KB

#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

const int delY[4] = { 0, 1, 0, -1 };
const int delX[4] = { 1, 0, -1, 0 };
const int nextK[6][4] = { {1, 2, 3, 4}, {5, 1, 0, 1}, {2, 5, 2, 0}, {0, 3, 5, 3}, {4, 0, 4, 5}, {3, 4, 1, 2} };

constexpr int inf = 987654321;

int main() {
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	//바닥면 방향 번호 <-z, -x, -y, +x, +y, +z>
	vector<vector<int>> dist[6]; //[바닥면방향][y][x]
	for (int k = 0; k < 6; ++k)
		dist[k].assign(N, vector<int>(M, inf));
	vector<string> board (N);
	for (int i = 0; i < N; ++i)
		cin >> board[i];
	int sY, sX, dY, dX;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == 'D') {
				sY = i; sX = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'R') {
				dY = i; dX = j;
				board[i][j] = '.';
			}
		}
	}

	queue<int> qK, qY, qX;
	qK.push(0);
	qY.push(sY);
	qX.push(sX);
	dist[0][sY][sX] = 0;
	while (!qK.empty()) {
		int curK = qK.front(); qK.pop();
		int curY = qY.front(); qY.pop();
		int curX = qX.front(); qX.pop();
		if (curY == dY && curX == dX) {
			if (curK == 0)
				break;
			else
				continue;
		}
		for (int dir = 0; dir < 4; ++dir) {
			int nY = curY + delY[dir];
			int nX = curX + delX[dir];
			int nK = nextK[curK][dir];
			if (nY < 0 || nY >= N || nX < 0 || nX >= M || board[nY][nX] != '.' || dist[nK][nY][nX] != inf)
				continue;
			dist[nK][nY][nX] = dist[curK][curY][curX] + 1;
			qK.push(nK);
			qY.push(nY);
			qX.push(nX);
		}
	}
	int ans = dist[0][dY][dX];
	if (ans == inf)
		cout << -1;
	else
		cout << ans;
}
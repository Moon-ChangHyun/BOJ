// 0ms, 2164KB

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

constexpr int inf = 987654321;

int N;
vector<vector<char>> board;

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	board.resize(N, vector<char>(N));

	vector<int> start, end;
	start.reserve(3); end.reserve(3);
	for (int i = 0; i < N; ++i) {
		cin >> ws;
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'B')
				start.push_back(i * N + j);
			else if (board[i][j] == 'E')
				end.push_back(i * N + j);
		}
	}

	int gY = end[1] / N;
	int gX = end[1] % N;
	int gR = end[0] + 1 == end[1];

	vector<vector<int>> dist[2];
	dist[0].assign(N, vector<int>(N, inf));
	dist[1].assign(N, vector<int>(N, inf));
	queue<int> qX, qY, qR;
	qY.push(start[1] / N);
	qX.push(start[1] % N);
	qR.push(start[0] + 1 == start[1]); //세로:0, 가로:1
	dist[qR.front()][qY.front()][qX.front()] = 0;

	while (!qX.empty()) {
		int cY = qY.front(); qY.pop();
		int cX = qX.front(); qX.pop();
		int cR = qR.front(); qR.pop();
		int curDist = dist[cR][cY][cX];
		if (cY == gY && cX == gX && cR == gR) break;

		if (cR) { //가로
			if (cX > 1 && dist[cR][cY][cX - 1] == inf && board[cY][cX - 2] != '1') {
				qY.push(cY);
				qX.push(cX - 1);
				qR.push(cR);
				dist[cR][cY][cX - 1] = curDist + 1;
			}
			if (cX < N - 2 && dist[cR][cY][cX + 1] == inf && board[cY][cX + 2] != '1') {
				qY.push(cY);
				qX.push(cX + 1);
				qR.push(cR);
				dist[cR][cY][cX + 1] = curDist + 1;
			}
			if (cY > 0 && dist[cR][cY - 1][cX] == inf && board[cY - 1][cX] != '1' && board[cY - 1][cX - 1] != '1' && board[cY - 1][cX + 1] != '1') {
				qY.push(cY - 1);
				qX.push(cX);
				qR.push(cR);
				dist[cR][cY - 1][cX] = curDist + 1;
			}
			if (cY < N - 1 && dist[cR][cY + 1][cX] == inf && board[cY + 1][cX] != '1' && board[cY + 1][cX - 1] != '1' && board[cY + 1][cX + 1] != '1') {
				qY.push(cY + 1);
				qX.push(cX);
				qR.push(cR);
				dist[cR][cY + 1][cX] = curDist + 1;
			}
			if (0 < cY && cY < N - 1 && dist[1 - cR][cY][cX] == inf &&
				board[cY - 1][cX - 1] != '1' && board[cY - 1][cX] != '1' && board[cY - 1][cX + 1] != '1' &&
				board[cY + 1][cX - 1] != '1' && board[cY + 1][cX] != '1' && board[cY + 1][cX + 1] != '1') {
				qY.push(cY);
				qX.push(cX);
				qR.push(1 - cR);
				dist[1 - cR][cY][cX] = curDist + 1;
			}
		}
		else { //세로
			if (cY > 1 && dist[cR][cY - 1][cX] == inf && board[cY - 2][cX] != '1') {
				qY.push(cY - 1);
				qX.push(cX);
				qR.push(cR);
				dist[cR][cY - 1][cX] = curDist + 1;
			}
			if (cY < N - 2 && dist[cR][cY + 1][cX] == inf && board[cY + 2][cX] != '1') {
				qY.push(cY + 1);
				qX.push(cX);
				qR.push(cR);
				dist[cR][cY + 1][cX] = curDist + 1;
			}
			if (cX > 0 && dist[cR][cY][cX - 1] == inf && board[cY][cX - 1] != '1' && board[cY - 1][cX - 1] != '1' && board[cY + 1][cX - 1] != '1') {
				qY.push(cY);
				qX.push(cX - 1);
				qR.push(cR);
				dist[cR][cY][cX - 1] = curDist + 1;
			}
			if (cX < N - 1 && dist[cR][cY][cX + 1] == inf && board[cY][cX + 1] != '1' && board[cY - 1][cX + 1] != '1' && board[cY + 1][cX + 1] != '1') {
				qY.push(cY);
				qX.push(cX + 1);
				qR.push(cR);
				dist[cR][cY][cX + 1] = curDist + 1;
			}
			if (0 < cX && cX < N - 1 && dist[1 - cR][cY][cX] == inf &&
				board[cY - 1][cX - 1] != '1' && board[cY][cX - 1] != '1' && board[cY + 1][cX - 1] != '1' &&
				board[cY - 1][cX + 1] != '1' && board[cY][cX + 1] != '1' && board[cY + 1][cX + 1] != '1') {
				qY.push(cY);
				qX.push(cX);
				qR.push(1 - cR);
				dist[1 - cR][cY][cX] = curDist + 1;
			}
		}
	}

	cout << (dist[gR][gY][gX] == inf ? 0 : dist[gR][gY][gX]);
}
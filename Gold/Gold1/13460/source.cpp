// 0ms, 1244KB

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct gameState {
	static vector<vector<bool>> isWall;
	static bool discovered[10][10][10][10];
	static int boardWidth, boardHeight, holeY, holeX;
	int rY, rX, bY, bX, depth;
};

vector<vector<bool>> gameState::isWall;
bool gameState::discovered[10][10][10][10];//by, bx, ry, rx
int gameState::boardWidth = 0;
int gameState::boardHeight = 0;
int gameState::holeY = 0;
int gameState::holeX = 0;

bool tilting(gameState& state, queue<gameState>& q) {
	gameState nextState;
	bool redGoal;
	bool blueGoal;
	nextState.depth = state.depth + 1;
	//위
	nextState.bX = state.bX;
	nextState.rX = state.rX;
	if (state.rY > state.bY) {
		for (int y = state.bY;; --y) {
			if (gameState::isWall[y - 1][nextState.bX] || (y == gameState::holeY && nextState.bX == gameState::holeX)) {
				nextState.bY = y;
				break;
			}
		}
		for (int y = state.rY;; --y) {
			if (gameState::isWall[y - 1][nextState.rX] || (y == gameState::holeY && nextState.rX == gameState::holeX) || (nextState.rX == nextState.bX && y - 1 == nextState.bY && !(nextState.bY == gameState::holeY && nextState.bX == gameState::holeX))) {
				nextState.rY = y;
				break;
			}
		}
	}
	else {
		for (int y = state.rY;; --y) {
			if (gameState::isWall[y - 1][nextState.rX] || (y == gameState::holeY && nextState.rX == gameState::holeX)) {
				nextState.rY = y;
				break;
			}
		}
		for (int y = state.bY;; --y) {
			if (gameState::isWall[y - 1][nextState.bX] || (y == gameState::holeY && nextState.bX == gameState::holeX) || (nextState.rX == nextState.bX && y - 1 == nextState.rY && !(nextState.rY == gameState::holeY && nextState.rX == gameState::holeX))) {
				nextState.bY = y;
				break;
			}
		}
	}
	redGoal = nextState.rX == gameState::holeX && nextState.rY == gameState::holeY;
	blueGoal = nextState.bX == gameState::holeX && nextState.bY == gameState::holeY;
	if (redGoal && !blueGoal)
		return true;
	else if (!blueGoal && !redGoal && !gameState::discovered[nextState.bY][nextState.bX][nextState.rY][nextState.rX]) {
		q.push(nextState);
		gameState::discovered[nextState.bY][nextState.bX][nextState.rY][nextState.rX] = true;
	}
	//오른쪽
	nextState.bY = state.bY;
	nextState.rY = state.rY;
	if (state.rX < state.bX) {
		for (int x = state.bX;; ++x) {
			if (gameState::isWall[nextState.bY][x + 1] || (x == gameState::holeX && nextState.bY == gameState::holeY)) {
				nextState.bX = x;
				break;
			}
		}
		for (int x = state.rX;; ++x) {
			if (gameState::isWall[nextState.rY][x + 1] || (x == gameState::holeX && nextState.rY == gameState::holeY) || (nextState.rY == nextState.bY && x + 1 == nextState.bX && !(nextState.bX == gameState::holeX && nextState.bY == gameState::holeY))) {
				nextState.rX = x;
				break;
			}
		}
	}
	else {
		for (int x = state.rX;; ++x) {
			if (gameState::isWall[nextState.rY][x + 1] || (x == gameState::holeX && nextState.rY == gameState::holeY)) {
				nextState.rX = x;
				break;
			}
		}
		for (int x = state.bX;; ++x) {
			if (gameState::isWall[nextState.bY][x + 1] || (x == gameState::holeX && nextState.bY == gameState::holeY) || (nextState.rY == nextState.bY && x + 1 == nextState.rX && !(nextState.rX == gameState::holeX && nextState.rY == gameState::holeY))) {
				nextState.bX = x;
				break;
			}
		}
	}
	redGoal = nextState.rX == gameState::holeX && nextState.rY == gameState::holeY;
	blueGoal = nextState.bX == gameState::holeX && nextState.bY == gameState::holeY;
	if (redGoal && !blueGoal)
		return true;
	else if (!blueGoal && !redGoal && !gameState::discovered[nextState.bY][nextState.bX][nextState.rY][nextState.rX]) {
		q.push(nextState);
		gameState::discovered[nextState.bY][nextState.bX][nextState.rY][nextState.rX] = true;
	}
	//아래
	nextState.bX = state.bX;
	nextState.rX = state.rX;
	if (state.rY < state.bY) {
		for (int y = state.bY;; ++y) {
			if (gameState::isWall[y + 1][nextState.bX] || (y == gameState::holeY && nextState.bX == gameState::holeX)) {
				nextState.bY = y;
				break;
			}
		}
		for (int y = state.rY;; ++y) {
			if (gameState::isWall[y + 1][nextState.rX] || (y == gameState::holeY && nextState.rX == gameState::holeX) || (nextState.rX == nextState.bX && y + 1 == nextState.bY && !(nextState.bY == gameState::holeY && nextState.bX == gameState::holeX))) {
				nextState.rY = y;
				break;
			}
		}
	}
	else {
		for (int y = state.rY;; ++y) {
			if (gameState::isWall[y + 1][nextState.rX] || (y == gameState::holeY && nextState.rX == gameState::holeX)) {
				nextState.rY = y;
				break;
			}
		}
		for (int y = state.bY;; ++y) {
			if (gameState::isWall[y + 1][nextState.bX] || (y == gameState::holeY && nextState.bX == gameState::holeX) || (nextState.rX == nextState.bX && y + 1 == nextState.rY && !(nextState.rY == gameState::holeY && nextState.rX == gameState::holeX))) {
				nextState.bY = y;
				break;
			}
		}
	}
	redGoal = nextState.rX == gameState::holeX && nextState.rY == gameState::holeY;
	blueGoal = nextState.bX == gameState::holeX && nextState.bY == gameState::holeY;
	if (redGoal && !blueGoal)
		return true;
	else if (!blueGoal && !redGoal && !gameState::discovered[nextState.bY][nextState.bX][nextState.rY][nextState.rX]) {
		q.push(nextState);
		gameState::discovered[nextState.bY][nextState.bX][nextState.rY][nextState.rX] = true;
	}
	//왼쪽
	nextState.bY = state.bY;
	nextState.rY = state.rY;
	if (state.rX > state.bX) {
		for (int x = state.bX;; --x) {
			if (gameState::isWall[nextState.bY][x - 1] || (x == gameState::holeX && nextState.bY == gameState::holeY)) {
				nextState.bX = x;
				break;
			}
		}
		for (int x = state.rX;; --x) {
			if (gameState::isWall[nextState.rY][x - 1] || (x == gameState::holeX && nextState.rY == gameState::holeY) || (nextState.rY == nextState.bY && x - 1 == nextState.bX && !(nextState.bX == gameState::holeX && nextState.bY == gameState::holeY))) {
				nextState.rX = x;
				break;
			}
		}
	}
	else {
		for (int x = state.rX;; --x) {
			if (gameState::isWall[nextState.rY][x - 1] || (x == gameState::holeX && nextState.rY == gameState::holeY)) {
				nextState.rX = x;
				break;
			}
		}
		for (int x = state.bX;; --x) {
			if (gameState::isWall[nextState.bY][x - 1] || (x == gameState::holeX && nextState.bY == gameState::holeY) || (nextState.rY == nextState.bY && x - 1 == nextState.rX && !(nextState.rX == gameState::holeX && nextState.rY == gameState::holeY))) {
				nextState.bX = x;
				break;
			}
		}
	}
	redGoal = nextState.rX == gameState::holeX && nextState.rY == gameState::holeY;
	blueGoal = nextState.bX == gameState::holeX && nextState.bY == gameState::holeY;
	if (redGoal && !blueGoal)
		return true;
	else if (!blueGoal && !redGoal && !gameState::discovered[nextState.bY][nextState.bX][nextState.rY][nextState.rX]) {
		q.push(nextState);
		gameState::discovered[nextState.bY][nextState.bX][nextState.rY][nextState.rX] = true;
	}

	return false;
}

int main() {
	int ret = -1;
	scanf("%d%d", &gameState::boardHeight, &gameState::boardWidth);
	gameState::isWall.resize(gameState::boardHeight, vector<bool>(gameState::boardWidth, false));
	gameState initState;
	for (int i = 0; i != gameState::boardHeight; ++i) {
		for (int j = 0; j != gameState::boardWidth; ++j) {
			char c;
			scanf(" %c", &c);
			if (c == '#') {
				gameState::isWall[i][j] = true;
			}
			else if (c == 'O') {
				gameState::holeY = i;
				gameState::holeX = j;
			}
			else if (c == 'R') {
				initState.rY = i;
				initState.rX = j;
			}
			else if (c == 'B') {
				initState.bY = i;
				initState.bX = j;
			}
		}
	}
	initState.depth = 0;
	queue<gameState> q;
	q.push(initState);
	gameState::discovered[initState.bY][initState.bX][initState.rY][initState.rX] = true;
	while (!q.empty()) {
		gameState curState = q.front(); q.pop();
		if (curState.depth == 10) break;
		if (tilting(curState, q)) {
			ret = curState.depth + 1;
			break;
		}
	}
	printf("%d", ret);
}
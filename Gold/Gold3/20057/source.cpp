// 32ms, 3084KB

#include<iostream>
#include<vector>
using namespace std;

const int offsetY[4][9] = {
	{ -2, -1, -1, -1, 0, 1, 1, 1, 2 },
	{0, 1, 0, -1, 2, 1, 0, -1, 0},
	{ 2, 1, 1, 1, 0, -1, -1, -1, -2 },
	{0, -1, 0, 1, -2, -1, 0, 1, 0}
};
const int offsetX[4][9] = {
	{ 0, -1, 0, 1, -2, -1, 0, 1, 0 },
	{ -2, -1, -1, -1, 0, 1, 1, 1, 2 },
	{0, 1, 0, -1, 2, 1, 0, -1, 0},
	{2, 1, 1, 1, 0, -1, -1, -1, -2}
};
const int ratio[9] = { 2, 10, 7, 1, 5, 10, 7, 1, 2 };
int N;
vector<vector<int>> arr;

enum class direction {
	left,
	down,
	right,
	up
};

void tornado(int y, int x, direction d) {
	auto& dy = offsetY[(int)d];
	auto& dx = offsetX[(int)d];
	int org = arr[y][x];
	int amount = org;
	arr[y][x] = 0;

	for (int k = 0; k < 9; ++k) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		int w = (long long)org * ratio[k] / 100;
		amount -= w;
		if (ny >= 0 && nx >= 0 && ny < N && nx < N)
			arr[ny][nx] += w;
	}

	switch (d)
	{
	case direction::left:
		if (x > 0)
			arr[y][x - 1] += amount;
		break;
	case direction::down:
		if (y < N - 1)
			arr[y + 1][x] += amount;
		break;
	case direction::right:
		if (x < N - 1)
			arr[y][x + 1] += amount;
		break;
	case direction::up:
		if (y > 0)
			arr[y - 1][x] += amount;
		break;
	}
}

void simulation() {
	int half = N / 2;
	int y = half, x = half;
	for (int k = 0; k < half; ++k) {
		int l = 2 * k + 1;
		for (int j = 0; j < l; ++j) {
			--x;
			tornado(y, x, direction::left);
		}
		for (int i = 0; i < l; ++i) {
			++y;
			tornado(y, x, direction::down);
		}
		++l;
		for (int j = 0; j < l; ++j) {
			++x;
			tornado(y, x, direction::right);
		}
		for (int i = 0; i < l; ++i) {
			--y;
			tornado(y, x, direction::up);
		}
	}
	for (int j = 1; j < N; ++j) {
		--x;
		tornado(y, x, direction::left);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	arr.resize(N, vector<int>(N));

	int total_prev = 0;
	for (auto& row : arr) {
		for (auto& cell : row) {
			cin >> cell;
			total_prev += cell;
		}
	}

	simulation();

	int total_next = 0;
	for (auto& row : arr) {
		for (auto cell : row) {
			total_next += cell;
		}
	}

	cout << total_prev - total_next;
}
// 128ms, 2360KB

#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

int N, R, L;
vector<vector<int>> board;

void swapBlock(int top, int left, int bottom, int right, int tY, int tX)
{
	int dY = tY - top;
	int dX = tX - left;

	for (int i = top; i < bottom; ++i) {
		for (int j = left; j < right; ++j) {
			swap(board[i][j], board[i + dY][j + dX]);
		}
	}
}

void flipH(int y, int unit, int h)
{
	int half = h >> 1;
	for (int sI = 0; sI < half; sI += unit) {
		swapBlock(y + sI, 0, y + sI + unit, L, y + h - sI - unit, 0);
	}
}

void flipW(int x, int unit, int w) 
{
	int half = w >> 1;
	for (int sJ = 0; sJ < half; sJ += unit) {
		swapBlock(0, x + sJ, L, x + sJ + unit, 0, x + w - sJ - unit);
	}
}

vector<function<void(int)>> func{ 
	[](int l) { // 1
		int sz = 1 << l;
		for (int i = 0; i < L; i += sz)
			flipH(i, 1, sz);
	},
	[](int l) { // 2
		int sz = 1 << l;
		for (int j = 0; j < L; j += sz)
			flipW(j, 1, sz);
	},
	[](int l) { // 3
		int sz = 1 << l;
		for (int y = 0; y < L; y += sz) {
			for (int x = 0; x < L; x += sz) {
				vector<vector<int>> tmp(sz, vector<int>(sz));
				for (int i = 0; i < sz; ++i)
					for (int j = 0; j < sz; ++j)
						tmp[i][j] = board[y + sz - 1 - j][x + i];
				for (int i = 0; i < sz; ++i)
					for (int j = 0; j < sz; ++j)
						board[y + i][x + j] = tmp[i][j];

			}
		}
	},
	[](int l) { // 4
		int sz = 1 << l;
		for (int y = 0; y < L; y += sz) {
			for (int x = 0; x < L; x += sz) {
				vector<vector<int>> tmp(sz, vector<int>(sz));
				for (int i = 0; i < sz; ++i)
					for (int j = 0; j < sz; ++j)
						tmp[i][j] = board[y + j][x + sz - 1 - i];
				for (int i = 0; i < sz; ++i)
					for (int j = 0; j < sz; ++j)
						board[y + i][x + j] = tmp[i][j];
			}
		}
	},
	[](int l) { // 5
		flipH(0, 1 << l, L);
	},
	[](int l) { // 6
		flipW(0, 1 << l, L);
	},
	[](int l) { // 7
		int unit = 1 << l;
		int sz = L / unit;
		vector<vector<int>> tmp(sz, vector<int>(sz));
		int cnt = -1;
		for (int j = sz - 1; j >= 0; --j) {
			for (int i = 0; i < sz; ++i) {
				tmp[i][j] = ++cnt;
			}
		}
		vector<vector<int>> result(L, vector<int>(L));
		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				int unitY = tmp[i][j] / sz;
				int unitX = tmp[i][j] % sz;
				int sY = unitY * unit;
				int sX = unitX * unit;
				int tY = i * unit;
				int tX = j * unit;
				for (int dy = 0; dy < unit; ++dy) {
					for (int dx = 0; dx < unit; ++dx) {
						result[tY + dy][tX + dx] = board[sY + dy][sX + dx];
					}
				}
			}
		}
		board = move(result);
	},
	[](int l) { // 8
		int unit = 1 << l;
		int sz = L / unit;
		vector<vector<int>> tmp(sz, vector<int>(sz));
		int cnt = -1;
		for (int j = 0; j < sz; ++j) {
			for (int i = sz - 1; i >= 0; --i) {
				tmp[i][j] = ++cnt;
			}
		}
		vector<vector<int>> result(L, vector<int>(L));
		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				int unitY = tmp[i][j] / sz;
				int unitX = tmp[i][j] % sz;
				int sY = unitY * unit;
				int sX = unitX * unit;
				int tY = i * unit;
				int tX = j * unit;
				for (int dy = 0; dy < unit; ++dy) {
					for (int dx = 0; dx < unit; ++dx) {
						result[tY + dy][tX + dx] = board[sY + dy][sX + dx];
					}
				}
			}
		}
		board = move(result);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> R;
	L = 1 << N;
	board.resize(L, vector<int>(L));
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			cin >> board[i][j];
		}
	}
	for (int r = 0; r < R; ++r) {
		int k, l;
		cin >> k >> l;
		func[k - 1](l);
	}
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}
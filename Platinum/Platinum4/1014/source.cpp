// 0ms, 2192KB

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int dp[10][1024];
char map[10][10];
vector<pair<int, int>> cand[10]; //행별 가능한 좌석 배치 조합<BM, 수>


int func(int row, int prevBM) {
	if (row == N) return 0;

	int& ret = dp[row][prevBM];
	if (ret != -1) return ret;
	ret = 0;

	int forbidden = 0;
	if (prevBM & 1)
		forbidden |= (1 << 1);
	if (prevBM & (1 << (M - 1)))
		forbidden |= (1 << (M - 2));
	for (int j = 1; j < M - 1; ++j) {
		if (prevBM & (1 << j)) {
			forbidden |= (1 << (j - 1));
			forbidden |= (1 << (j + 1));
		}
	}

	for (const auto& next : cand[row]) {
		if (next.first & forbidden)
			continue;
		ret = max(ret, next.second + func(row + 1, next.first));
	}

	return ret;
}

void makeCand(int row, int col, int bm, int num) {
	if (col >= M) {
		cand[row].emplace_back(bm, num);
		return;
	}
	makeCand(row, col + 1, bm, num);
	if (map[row][col] == '.') {
		makeCand(row, col + 2, bm | (1 << col), num + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> skipws;
	int C;
	for (cin >> C; ~--C; ) {
		cin >> N >> M;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				cin >> map[i][j];

		int jEnd = 1 << M;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < jEnd; ++j)
				dp[i][j] = -1;

		for (int i = 0; i < N; ++i) {
			cand[i].clear();
			makeCand(i, 0, 0, 0);
		}

		cout << func(0, 0) << '\n';
	}
}
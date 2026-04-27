// 144ms, 2284KB

#include<iostream>
#include<vector>

using namespace std;

constexpr int dy[4] = { 0, 1, 0, -1 };
constexpr int dx[4] = { 1, 0, -1, 0 };

int N, Q, L;
vector<vector<int>> ice;

void rotate(int y, int x, int l) {
	vector<vector<int>> tmp(l, vector<int>(l));
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < l; ++j) {
			tmp[j][l - 1 - i] = ice[y + i][x + j];
		}
	}
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < l; ++j) {
			ice[y + i][x + j] = tmp[i][j];
		}
	}
}

void simulation(int e) {
	int l = 1 << e;
	for (int i = 0; i < L; i += l) {
		for (int j = 0; j < L; j += l) {
			rotate(i, j, l);
		}
	}

	vector<vector<int>> cnt(L, vector<int>(L));
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			for (int k = 0; k < 4; ++k) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= L || nx >= L)
					continue;
				cnt[i][j] += (ice[ny][nx] > 0);
			}
		}
	}

	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			if (ice[i][j] > 0 && cnt[i][j] < 3) {
				--ice[i][j];
			}
		}
	}
}

vector<vector<bool>> visit;
int dfs(int y, int x) {
	visit[y][x] = true;
	int ret = 1;
	for (int k = 0; k < 4; ++k) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= L || nx >= L || ice[ny][nx] == 0 || visit[ny][nx])
			continue;
		ret += dfs(ny, nx);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> Q;
	L = 1 << N;
	ice.resize(L, vector<int>(L));
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			cin >> ice[i][j];
		}
	}
	for (int q = 0; q < Q; ++q) {
		int e;
		cin >> e;
		simulation(e);
	}

	int iceSum = 0;
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			iceSum += ice[i][j];
		}
	}
	cout << iceSum << '\n';

	int maxSize = 0;
	visit.resize(L, vector<bool>(L));
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			if (ice[i][j] > 0 && !visit[i][j]) {
				maxSize = max(maxSize, dfs(i, j));
			}
		}
	}
	cout << maxSize;
}
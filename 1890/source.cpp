#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<vector<int>> board;
vector<vector<long long>> cache;

long long f(int y, int x) {
	if (y == n - 1 && x == n - 1)
		return 1;
	long long& ret = cache[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	if (y + board[y][x] < n)
		ret += f(y + board[y][x], x);
	if (x + board[y][x] < n)
		ret += f(y, x + board[y][x]);
	return ret;
}

int main() {
	scanf("%d", &n);
	board.resize(n);
	cache.resize(n);
	for (int i = 0; i != n; ++i) {
		board[i].resize(n);
		cache[i].resize(n);
		for (int j = 0; j != n; ++j) {
			scanf("%d", &board[i][j]);
			cache[i][j] = -1;
		}
	}
	printf("%lld", f(0, 0));
}
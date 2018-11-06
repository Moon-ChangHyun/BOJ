#include<cstdio>
#include<vector>
using namespace std;
int N;
double PE, PW, PS, PN;
vector<vector<bool>> visit;
double ret = 0;
void dfs(int rem, double p, int y, int x) {
	if (visit[y][x]) return;
	if (rem == 0) {
		ret += p;
		return;
	}
	visit[y][x] = true;
	dfs(rem - 1, p * PE, y, x + 1);
	dfs(rem - 1, p * PW, y, x - 1);
	dfs(rem - 1, p * PS, y + 1, x);
	dfs(rem - 1, p * PN, y - 1, x);
	visit[y][x] = false;
}
int main() {
	int e, w, s, n;
	scanf("%d%d%d%d%d", &N, &e, &w, &s, &n);
	PE = e / 100.0;
	PW = w / 100.0;
	PS = s / 100.0;
	PN = n / 100.0;
	visit.resize(2 * N + 1, vector<bool>(2 * N + 1, false));
	dfs(N, 1, N, N);
	printf("%.12f", ret);
}
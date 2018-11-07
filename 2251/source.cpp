#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int a, b, c;
vector<vector<bool>> visit(201, vector<bool>(201, false));

void dfs(int curB, int curC) {
	if (visit[curB][curC]) return;
	visit[curB][curC] = true;
	int curA = c - (curB + curC);
	if (curA) {
		dfs(min(b, curA + curB), curC);
		dfs(curB, curA + curC);
	}
	if (curB) {
		dfs(curA + curB - min(a, curA + curB), curC);
		dfs(0, curB + curC);
	}
	if (curC) {
		dfs(curB, curA + curC - min(a, curA + curC));
		dfs(min(b, curB + curC), curB + curC - min(b, curB + curC));
	}
}

int main() {
	scanf("%d%d%d", &a, &b, &c);
	dfs(0, c);
	for (int i = 0; i <= c; ++i)
		if (visit[c - i][i])
			printf("%d ", i);
}
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int n, k, p, dep;
	scanf("%d%d", &n, &k);
	vector<bool> visit(100001, false);
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visit[n] = true;
	while (p != k) {
		p = q.front().first;
		dep = q.front().second;
		q.pop();
		if (p != 0 && !visit[p - 1]) {
			q.push({ p - 1 , dep + 1 });
			visit[p - 1] = true;
		}
		if (p != 100000 && !visit[p + 1]) {
			q.push({ p + 1 , dep + 1 });
			visit[p + 1] = true;
		}
		if (p <= 50000 && !visit[2 * p]) {
			q.push({ 2 * p , dep + 1 });
			visit[2 * p] = true;
		}
	}
	printf("%d", dep);
}
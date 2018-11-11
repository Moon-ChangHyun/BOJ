#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int main() {
	int n, src, dst;
	scanf("%d%d%d", &n, &src, &dst);
	int m;
	scanf("%d", &m);
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i != m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> nq;
	queue<int> dq;
	vector<bool> discovered(n + 1, false);
	discovered[src] = true;
	nq.push(src);
	dq.push(0);
	int ret = -1;
	while (!nq.empty()) {
		int num = nq.front(); nq.pop();
		int dep = dq.front(); dq.pop();
		if (num == dst) {
			ret = dep;
			break;
		}
		for (auto iter : adj[num]) {
			if (!discovered[iter]) {
				discovered[iter] = true;
				nq.push(iter);
				dq.push(dep + 1);
			}
		}
	}
	printf("%d", ret);
}
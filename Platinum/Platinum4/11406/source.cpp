// 212ms, 1496KB

#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> capacity;
vector<vector<int>> flow;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	capacity.resize(N + M + 2, vector<int>(N + M + 2));
	flow.resize(N + M + 2, vector<int>(N + M + 2, 0));
	for(int i = 1; i <= N; ++i) {
		int x;
		scanf("%d", &x);
		capacity[0][i] = x;
	}
	for(int i = N + 1; i <= N + M; ++i) {
		int x;
		scanf("%d", &x);
		capacity[i][N + M + 1] = x;
	}
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			int x;
			scanf("%d", &x);
			capacity[j][i + N] = x;
		}
	}
	int totalFlow = 0;
	while(true) {
		vector<int> parent(N + M + 2, -1);
		queue<int> q;
		parent[0] = 0;
		q.push(0);
		while(!q.empty() && parent[N + M + 1] == -1) {
			int here = q.front(); q.pop();
			for(int there = 1; there <= N + M + 1; ++there) {
				if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if(parent[N + M + 1] == -1) break;
		int amount = 101;
		for (int p = N + M + 1; p; p = parent[p])
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		for (int p = N + M + 1; p; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	printf("%d", totalFlow);
}
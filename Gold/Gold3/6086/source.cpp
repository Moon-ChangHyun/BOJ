// 0ms, 1348KB

#include <cstdio>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;
array<array<int, 123>, 123> cap;
array<array<int, 123>, 123> flow;
int main() {
	int N, c;
	char s, d;
	scanf("%d", &N);
	for (int i = 0; i != N; ++i) {
		scanf(" %c %c%d", &s, &d, &c);
		cap[s][d] += c;
		cap[d][s] += c;
	}
	int totalFlow = 0;
	while (true) {
		array<int, 123> parent = {0};
		queue<int> q;
		parent['A'] = 'A';
		q.push('A');
		while (!q.empty() && !parent['Z']) {
			int here = q.front();
			q.pop();
			for (int there = 'A'; there <= 'z'; ++there) {
				if (cap[here][there] - flow[here][there] > 0 && !parent[there]) {
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if (!parent['Z']) break;
		int amount = 1001;
		for (int p = 'Z'; p != 'A'; p = parent[p])
			amount = min(cap[parent[p]][p] - flow[parent[p]][p], amount);
		for (int p = 'Z'; p != 'A'; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	printf("%d", totalFlow);
}
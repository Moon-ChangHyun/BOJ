// 160ms, 14672KB

#include<queue>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, D, E;
	cin >> N >> M >> D >> E;
	vector<int> height(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> height[i];
	vector<vector<pair<int, int>>> adj(N + 1);
	for (int i = 1; i <= M; ++i) {
		int a, b, n;
		cin >> a >> b >> n;
		adj[a].push_back({ b, n });
		adj[b].push_back({ a, n });
	}
	vector<long long> ascDist(N + 1, 987654321987654), descDist(N + 1, 987654321987654);
	priority_queue<pair<long long, int>> pq;// -거리, 정점
	ascDist[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		auto tmp = pq.top(); pq.pop();
		long long dist = -tmp.first;
		int vert = tmp.second;
		if (ascDist[vert] < dist) continue;
		for (auto next : adj[vert]) {
			int nextVert = next.first, nextDist = next.second;
			if (height[vert] >= height[nextVert]) continue;
			if (dist + nextDist < ascDist[nextVert]) {
				ascDist[nextVert] = dist + nextDist;
				pq.push({ -(dist + nextDist), nextVert });
			}
		}
	}
	descDist[N] = 0;
	pq.push({ 0, N });
	while (!pq.empty()) {
		auto tmp = pq.top(); pq.pop();
		long long dist = -tmp.first;
		int vert = tmp.second;
		if (descDist[vert] < dist) continue;
		for (auto next : adj[vert]) {
			int nextVert = next.first, nextDist = next.second;
			if (height[vert] >= height[nextVert]) continue;
			if (dist + nextDist < descDist[nextVert]) {
				descDist[nextVert] = dist + nextDist;
				pq.push({ -(dist + nextDist), nextVert });
			}
		}
	}
	bool findAnyPath = false;
	long long ret = -987654321987654;
	for (int i = 1; i <= N; ++i) {
		if (ascDist[i] != 987654321987654 && descDist[i] != 987654321987654) {
			findAnyPath = true;
			ret = max(ret, ((long long)height[i] * E) - ((ascDist[i] + descDist[i]) * D));
		}
	}
	if (findAnyPath) {
		cout << ret;
	}
	else {
		cout << "Impossible";
	}
}
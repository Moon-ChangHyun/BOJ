// 360ms, 30372KB

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
using ll = long long;

constexpr ll inf = 987654321987654321;

int main() {

	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> adj(N + 1); //adj[i] = i번지역에서 연결된 지역정보 <지역번호, 신호시간> 리스트

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}

	vector<ll> dist(N + 1, inf); //최단시간
	priority_queue<pair<ll, int>> pq; // <-경과시간, 지역번호>

	dist[1] = 0;
	pq.emplace(0, 1);

	while (!pq.empty())
	{
		auto nd = pq.top().second;
		auto t = -pq.top().first;
		pq.pop();
		if (nd == N) break;
		if (dist[nd] < t) continue;
		auto k = t % M;
		for (auto& next : adj[nd]) {
			auto waitTime = next.second - k;
			if (waitTime < 0) {
				waitTime += M;
			}
			auto nextTime = t + waitTime + 1;
			if (dist[next.first] > nextTime) {
				dist[next.first] = nextTime;
				pq.emplace(-nextTime, next.first);
			}
		}
	}

	cout << dist[N];
}
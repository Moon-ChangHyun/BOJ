// 96ms, 11612KB

#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 987654321987
using namespace std;

int main() {
	int N, M, ret = 0;
	scanf("%d%d", &N, &M);
	vector<vector<pair<int, int>>> adj(N + 1);
	for(int i = 0; i != M; ++i) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d << 1});
		adj[b].push_back({a, d << 1});
	}
	vector<long long> foxDist(N + 1, INF), wolfOddDist(N + 1, INF), wolfEvenDist(N + 1, INF);
	priority_queue<pair<long long, int>> foxQ;
	foxQ.push({0, 1});
	foxDist[1] = 0;
	while(!foxQ.empty()) {
		long long dst = -foxQ.top().first;
		int node = foxQ.top().second;
		foxQ.pop();
		if(foxDist[node] < dst)
			continue;
		for(auto& next : adj[node]) {
			long long nextDst = dst + next.second;
			int nextNode = next.first;
			if(foxDist[nextNode] > nextDst) {
				foxQ.push({-nextDst, nextNode});
				foxDist[nextNode] = nextDst;
			}
		}
	}
	priority_queue<pair<long long, pair<int, bool>>> wolfQ;
	wolfQ.push({0, {1, true}});
	wolfOddDist[1] = 0;
	while(!wolfQ.empty()) {
		long long dst = -wolfQ.top().first;
		int node = wolfQ.top().second.first;
		bool isOdd = wolfQ.top().second.second;
		wolfQ.pop();
		if(isOdd) {
			if(wolfOddDist[node] < dst)
				continue;
			for(auto& next : adj[node]) {
				long long nextDst = dst + (next.second >> 1);
				int nextNode = next.first;
				if(wolfEvenDist[nextNode] > nextDst) {
					wolfQ.push({-nextDst, {nextNode, false}});
					wolfEvenDist[nextNode] = nextDst;
				}
			}
		}
		else {
			if(wolfEvenDist[node] < dst)
				continue;
			for(auto& next : adj[node]) {
				long long nextDst = dst + (next.second << 1);
				int nextNode = next.first;
				if(wolfOddDist[nextNode] > nextDst) {
					wolfQ.push({-nextDst, {nextNode, true}});
					wolfOddDist[nextNode] = nextDst;
				}
			}
		}
	}
	for(int i = 2; i <= N; ++i)
		ret += (foxDist[i] < min(wolfOddDist[i], wolfEvenDist[i]));
	printf("%d", ret);
}
#include<cstdio>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

int main() {
	int T;
	for (scanf("%d", &T); ~--T; ) {
		int N, K;
		scanf("%d%d", &N, &K);
		vector<int> delay(N + 1);
		vector<vector<int>> adj(N + 1);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &delay[i]);
		}
		for (int i = 0; i != K; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[b].push_back(a);
		}
		int W;
		scanf("%d", &W);
		vector<int> cache;
		cache.reserve(N + 1);
		for (int i = 0; i <= N; ++i)
			cache.push_back(-1);
		function<int(int)> f = [&f, &cache, &delay, &adj](int pos) {
			if (adj[pos].size() == 0)
				return delay[pos];
			int& ret = cache[pos];
			if (ret != -1)
				return ret;
			for (auto& iter : adj[pos]) {
				ret = max(f(iter), ret);
			}
			return ret += delay[pos];
		};
		printf("%d\n", f(W));
	}
}

#include<cstdio>
#include<vector>
#include<list>
#include<set>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	set<pair<int, int>> inputVertex;
	vector<list<int>> adj(n + 1);
	vector<int> inputCnt(n + 1);
	for (int i = 0; i != m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		++inputCnt[b];
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i)
		inputVertex.insert({ inputCnt[i], i });
	while (inputVertex.size()) {
		auto temp = *inputVertex.begin();
		inputVertex.erase(inputVertex.begin());
		printf("%d ", temp.second);
		for (auto& iter : adj[temp.second]) {
			auto inIter = inputVertex.find({ inputCnt[iter], iter });
			--inputCnt[iter];
			inputVertex.erase(inIter);
			inputVertex.insert({ inputCnt[iter], iter });
		}
		adj[temp.second].clear();
	}
}
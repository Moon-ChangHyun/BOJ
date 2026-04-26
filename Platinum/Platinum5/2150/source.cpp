// 32ms, 2784KB

#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int V, E, ai;
vector<bool> finished;
vector<int> visitNum;
vector<vector<int>> adj;
stack<int> st;
vector<vector<int>> SCC;

int dfs(int node) {
	int result = visitNum[node] = ++ai;
	st.push(node);
	for (auto next : adj[node]) {
		if (!visitNum[next]) {
			result = min(result, dfs(next));
		}
		else if (!finished[next]) {
			result = min(result, visitNum[next]);
		}
	}
	if (result == visitNum[node]) {
		vector<int> scc;
		while (true) {
			int val = st.top(); st.pop();
			scc.push_back(val);
			finished[val] = true;
			if (val == node)
				break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(move(scc));
	}
	return result;
}

int main() {
	scanf("%d%d", &V, &E);
	adj.resize(V + 1);
	finished.resize(V + 1, false);
	visitNum.resize(V + 1, 0);
	for (int i = 0; i != E; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}
	for (int i = 1; i <= V; ++i) {
		if (!visitNum[i]) dfs(i);
	}
	sort(SCC.begin(), SCC.end(), [](vector<int>& scc1, vector<int>& scc2) {
		return scc1[0] < scc2[0];
	});
	printf("%d\n", SCC.size());
	for (auto& scc : SCC) {
		for (auto num : scc)
			printf("%d ", num);
		printf("-1\n");
	}
}
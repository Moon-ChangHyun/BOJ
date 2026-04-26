// 168ms, 22544KB

#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> adj;
vector<bool> finished;
vector<bool> income;
vector<int> discovered;
vector<int> sccId;
stack<int> st;
int ai, sccNum;
int scc(int node) {
	int result = discovered[node] = ++ai;
	st.push(node);
	for (auto next : adj[node]) {
		if (!discovered[next]) {
			result = min(result, scc(next));
		}
		else if (!finished[next]) {
			result = min(result, discovered[next]);
		}
		if (finished[next]) {
			income[sccId[next]] = true;
		}
	}
	if (result == discovered[node]) {
		int newSCCId = sccNum++;
		while (true) {
			int val = st.top(); st.pop();
			finished[val] = true;
			sccId[val] = newSCCId;
			if (val == node)
				break;
		}
		income.push_back(false);
	}
	return result;
}

int main() {
	int T;
	for (scanf("%d", &T); ~--T; ) {
		int N, M;
		scanf("%d%d", &N, &M);
		adj = vector<vector<int>>(N + 1);
		finished = vector<bool>(N + 1);
		income.clear();
		discovered = vector<int>(N + 1, 0);
		sccId = vector<int>(N + 1, -1);
		st = stack<int>();
		ai = 0, sccNum = 0;
		for (int i = 0; i != M; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
		}
		for (int i = 1; i <= N; ++i) {
			if (!discovered[i]) scc(i);
		}
		int ret = 0;
		for (auto hasIncome : income) {
			if (!hasIncome)
				++ret;
		}
		printf("%d\n", ret);
	}
}
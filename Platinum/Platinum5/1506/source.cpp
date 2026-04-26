// 0ms, 1232KB

#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N, ans, vertexCnt, sccCnt;
vector<int> discovered, cost;
vector<bool> determined;
vector<vector<int>> adj;
stack<int> st;

int scc(int here)
{
	int ret = discovered[here] = vertexCnt++;
	st.push(here);
	for (auto there : adj[here])
	{
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		else if (discovered[there] < discovered[here] && !determined[there])
			ret = min(ret, discovered[there]);
	}
	if (ret == discovered[here])
	{
		int minCost = 1000001;
		while (true)
		{
			int t = st.top(); st.pop();
			determined[t] = true;
			minCost = min(minCost, cost[t]);
			if (t == here) break;
		}
		ans += minCost;
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	cost.resize(N);
	adj.resize(N);
	determined.resize(N, false);
	discovered.resize(N, -1);
	for (int i = 0; i < N; ++i)
		scanf("%d", &cost[i]);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int val;
			scanf("%1d", &val);
			if (val)
				adj[i].push_back(j);
		}
	}
	for (int i = 0; i < N; ++i)
		if (discovered[i] == -1)
			scc(i);
	printf("%d", ans);
}
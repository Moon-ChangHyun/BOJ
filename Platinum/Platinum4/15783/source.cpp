// 32ms, 7592KB

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N, M, vertexCnt, sccCnt;
vector<vector<int>> adj;
vector<int> sccId, discovered;
stack<int> st;

int scc(int here)
{
	int ret = discovered[here] = vertexCnt++;
	st.push(here);
	for (auto there : adj[here])
	{
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		else if (discovered[there] < discovered[here] && sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	if (ret == discovered[here])
	{
		while (true)
		{
			int t = st.top(); st.pop();
			sccId[t] = sccCnt;
			if (t == here) break;
		}
		++sccCnt;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	adj.resize(N);
	discovered.resize(N, -1);
	sccId.resize(N, -1);
	
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 0; i < N; ++i)
		if (discovered[i] == -1)
			scc(i);

	vector<bool> hasInput(sccCnt, false);
	for (int i = 0; i < N; ++i)
		for (auto j : adj[i])
			if (sccId[i] != sccId[j])
				hasInput[sccId[j]] = true;
	int ans = 0;
	for (auto b : hasInput)
		if (!b) ++ans;
	cout << ans;
}
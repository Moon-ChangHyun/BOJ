// 512ms, 15404KB

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N, M, sccCnt, vertexCnt;
vector<vector<int>> adj;
vector<int> discovered, sccId;
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

bool solve2SAT()
{
	for (int i = 1; i <= N; ++i)
	{
		int node = i * 2;
		if (discovered[node] == -1)
			scc(node);
		++node;
		if (discovered[node] == -1)
			scc(node);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (sccId[i * 2] == sccId[i * 2 + 1])
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		if (!(cin >> N >> M)) break;
		adj.resize(N * 2 + 2);
		discovered.resize(N * 2 + 2, -1);
		sccId.resize(N * 2 + 2, -1);
		for (int i = 0; i < M; ++i)
		{
			int a, b, notA, notB;
			cin >> a >> b;
			if (a > 0)
			{
				a *= 2;
				notA = a + 1;
			}
			else
			{
				notA = -2 * a;
				a = notA + 1;
			}
			if (b > 0)
			{
				b *= 2;
				notB = b + 1;
			}
			else
			{
				notB = -2 * b;
				b = notB + 1;
			}
			adj[notA].push_back(b);
			adj[notB].push_back(a);
		}
		cout << solve2SAT() << '\n';
		discovered.clear();
		sccId.clear();
		adj.clear();
		sccCnt = vertexCnt = 0;
	}
}
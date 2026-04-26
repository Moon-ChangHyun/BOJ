// 396ms, 7668KB

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N, M, vertexCnt, sccCnt;
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

bool solve2Sat()
{
	for (int i = 1; i <= M; ++i)
	{
		int node = i << 1;
		if (discovered[node] == -1)
			scc(node);
		++node;
		if (discovered[node] == -1)
			scc(node);
	}
	for (int i = 1; i <= M; ++i)
		if (sccId[i << 1] == sccId[(i << 1) + 1])
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		adj.clear();
		discovered.clear();
		sccId.clear();
		adj.resize(2 * M + 2);
		discovered.resize(2 * M + 2, -1);
		sccId.resize(2 * M + 2, -1);
		vertexCnt = sccCnt = 0;
		for (int i = 0; i < N; ++i)
		{
			int a, b, notA, notB;
			cin >> a >> b;
			if (a < 0)
			{
				a *= -2;
				notA = a + 1;
			}
			else
			{
				notA = a * 2;
				a = notA + 1;
			}
			if (b < 0)
			{
				b *= -2;
				notB = b + 1;
			}
			else
			{
				notB = b * 2;
				b = notB + 1;
			}
			adj[notA].push_back(b);
			adj[notB].push_back(a);
		}
		cout << solve2Sat() << '\n';
	}
}
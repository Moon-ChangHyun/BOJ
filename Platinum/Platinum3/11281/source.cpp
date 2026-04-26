// 32ms, 5200KB

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> sccId, discovered;
int sccCnt, vertexCnt;
stack<int> st;

int tarjanSCC(int here)
{
	int ret = discovered[here] = vertexCnt++;
	st.push(here);
	for (auto there : adj[here])
	{
		if (discovered[there] == -1)
			ret = min(ret, tarjanSCC(there));
		else if (discovered[there] < discovered[here] && sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	if (ret == discovered[here])
	{
		while (true) {
			int t = st.top(); st.pop();
			sccId[t] = sccCnt;
			if (t == here) break;
		}
		++sccCnt;
	}
	return ret;
}

vector<int> solve2SAT()
{
	for (int i = 2; i < adj.size(); ++i)
		if (discovered[i] == -1)
			tarjanSCC(i);
	for (int i = 2; i < adj.size(); i += 2)
		if (sccId[i] == sccId[i + 1])
			return vector<int>();
	vector<int> value(N + 1, -1);
	vector<pair<int, int>> order;
	for (int i = 2; i < adj.size(); ++i)
		order.emplace_back(-sccId[i], i);
	sort(order.begin(), order.end());
	for (auto i : order)
	{
		int v = i.second;
		int variable = v / 2;
		if (value[variable] != -1) continue;
		value[variable] = v & 1;
	}
	return value;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M;
	adj.resize(2 * N + 2);
	sccId.resize(2 * N + 2, -1);
	discovered.resize(2 * N + 2, -1);
	for (int i = 0; i < M; ++i)
	{
		int a, b, notA, notB;
		cin >> a >> b;
		a *= 2;
		b *= 2;
		if (a < 0) {
			a = -a + 1;
			notA = a - 1;
		}
		else {
			notA = a + 1;
		}
		if (b < 0) {
			b = -b + 1;
			notB = b - 1;
		}
		else {
			notB = b + 1;
		}
		adj[notA].push_back(b);
		adj[notB].push_back(a);
	}
	auto ans = solve2SAT();
	cout << !ans.empty() << '\n';
	if (!ans.empty())
	{
		for (int i = 1; i < ans.size(); ++i)
		{
			cout << ans[i] << ' ';
		}
	}
}
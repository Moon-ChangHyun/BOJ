// 432ms, 45756KB

#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

class SegTree
{
	int n;
	vector<ll> lazy;
	void Update(int left, int right, int delta, int nodeLeft, int nodeRight, int node)
	{
		int len = nodeRight - nodeLeft + 1;
		int lc = node << 1, rc = lc + 1;
		if (lazy[node])
		{
			if (len > 1)
			{
				lazy[lc] += lazy[node];
				lazy[rc] += lazy[node];
				lazy[node] = 0;
			}
		}

		if (right < nodeLeft || nodeRight < left) return;
		if (left <= nodeLeft && nodeRight <= right)
		{
			lazy[node] += delta;
		}
		else
		{
			int mid = (nodeLeft + nodeRight) >> 1;
			Update(left, right, delta, nodeLeft, mid, lc);
			Update(left, right, delta, mid + 1, nodeRight, rc);
		}
	}
	ll GetBalance(int idx, int nodeLeft, int nodeRight, int node)
	{
		int len = nodeRight - nodeLeft + 1;
		if (len == 1)
			return lazy[node];

		int lc = node << 1, rc = lc + 1;
		if (lazy[node])
		{
			lazy[lc] += lazy[node];
			lazy[rc] += lazy[node];
			lazy[node] = 0;
		}

		int mid = (nodeLeft + nodeRight) >> 1;
		if (idx <= mid)
			return GetBalance(idx, nodeLeft, mid, lc);
		else
			return GetBalance(idx, mid + 1, nodeRight, rc);
	}
public:
	SegTree(int sz) : n(sz), lazy(sz << 2) {}
	void Update(int left, int right, int delta)
	{
		if (left <= right)
			Update(left, right, delta, 0, n - 1, 1);
	}
	int GetBalance(int idx)
	{
		return GetBalance(idx, 0, n - 1, 1);
	}
};

int counter = -1;
vector<int> base;
vector<vector<int>> children;
vector<int> rangeS, rangeE;

void dfs(int num)
{
	rangeS[num] = ++counter;
	for (auto child : children[num])
		dfs(child);
	rangeE[num] = counter;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	base.resize(N + 1);
	children.resize(N + 1);
	rangeS.resize(N + 1);
	rangeE.resize(N + 1);

	cin >> base[1];
	for (int i = 2; i <= N; ++i)
	{
		int p;
		cin >> base[i] >> p;
		children[p].push_back(i);
	}
	dfs(1);
	SegTree segTree(N);
	for (int i = 0; i < M; ++i)
	{
		char op;
		int a, x;
		cin >> op >> a;
		if (op == 'p')
		{
			cin >> x;
			segTree.Update(rangeS[a] + 1, rangeE[a], x);
		}
		else
		{
			cout << base[a] + segTree.GetBalance(rangeS[a]) << '\n';
		}
	}
}
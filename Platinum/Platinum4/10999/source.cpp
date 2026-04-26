// 216ms, 72348KB

#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

class SegTree {
	int n;
	vector<ll> rangeSum;
	vector<ll> lazy;

	ll init(const vector<ll>& arr, int nodeLeft, int nodeRight, int node)
	{
		if (nodeLeft == nodeRight)
			return rangeSum[node] = arr[nodeLeft];
		int mid = (nodeLeft + nodeRight) >> 1;
		return rangeSum[node] = init(arr, nodeLeft, mid, node << 1) + init(arr, mid + 1, nodeRight, (node << 1) + 1);
	}

	void update(int left, int right, ll delta, int nodeLeft, int nodeRight, int node)
	{
		int len = nodeRight - nodeLeft + 1;
		int lc = node << 1, rc = lc + 1;
		if (lazy[node])
		{
			rangeSum[node] += len * lazy[node];
			if (len > 1)
			{
				lazy[lc] += lazy[node];
				lazy[rc] += lazy[node];
			}
			lazy[node] = 0;
		}

		if (right < nodeLeft || nodeRight < left)
			return;
		if (left <= nodeLeft && nodeRight <= right)
		{
			rangeSum[node] += len * delta;
			if (len > 1)
			{
				lazy[lc] += delta;
				lazy[rc] += delta;
			}
		}
		else
		{
			int mid = (nodeLeft + nodeRight) >> 1;
			update(left, right, delta, nodeLeft, mid, lc);
			update(left, right, delta, mid + 1, nodeRight, rc);
			rangeSum[node] = rangeSum[lc] + rangeSum[rc];
		}
	}
	
	ll query(int left, int right, int nodeLeft, int nodeRight, int node)
	{
		int len = nodeRight - nodeLeft + 1;
		int lc = node << 1, rc = lc + 1;
		if (lazy[node])
		{
			rangeSum[node] += len * lazy[node];
			if (len > 1)
			{
				lazy[lc] += lazy[node];
				lazy[rc] += lazy[node];
			}
			lazy[node] = 0;
		}

		if (right < nodeLeft || nodeRight < left)
			return 0;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeSum[node];
		int mid = (nodeLeft + nodeRight) >> 1;
		return query(left, right, nodeLeft, mid, lc) + query(left, right, mid + 1, nodeRight, rc);
	}

public:
	SegTree(const vector<ll>& arr) : n(arr.size()), rangeSum(n << 2), lazy(n << 2)
	{
		init(arr, 0, n - 1, 1);
	}

	void update(int left, int right, ll delta)
	{
		update(left - 1, right - 1, delta, 0, n - 1, 1);
	}

	ll query(int left, int right)
	{
		return query(left - 1, right - 1, 0, n - 1, 1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, K, Q;
	cin >> N >> M >> K;
	vector<ll> arr(N);
	for (auto& val : arr)
		cin >> val;
	SegTree segTree(arr);
	Q = M + K;
	for (int i = 0; i < Q; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			ll d;
			cin >> d;
			segTree.update(b, c, d);
		}
		else
		{
			cout << segTree.query(b, c) << '\n';
		}
	}
}
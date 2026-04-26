// 272ms, 23336KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class RMQ {
	int n;
	vector<vector<int>> rangeSorted;
	void init(const vector<int>& v, int l, int r, int nd)
	{
		rangeSorted[nd].resize(r - l + 1);
		if (l == r) {
			rangeSorted[nd][0] = v[l];
			return;
		}
		int mid = (l + r) >> 1;
		int ndL = nd << 1;
		int ndR = ndL + 1;
		init(v, l, mid, ndL);
		init(v, mid + 1, r, ndR);
		merge(rangeSorted[ndL].begin(), rangeSorted[ndL].end(),
			rangeSorted[ndR].begin(), rangeSorted[ndR].end(),
			rangeSorted[nd].begin());
	}

	int query(int l, int r, int k, int nd, int ndL, int ndR)
	{
		if (r < ndL || ndR < l) return 0;
		if (l <= ndL && ndR <= r)
			return rangeSorted[nd].end() - upper_bound(rangeSorted[nd].begin(), rangeSorted[nd].end(), k);
		int mid = (ndL + ndR) >> 1;
		return query(l, r, k, nd << 1, ndL, mid) + query(l, r, k, (nd << 1) + 1, mid + 1, ndR);
	}

public:
	RMQ(const vector<int>& v) : n(v.size()), rangeSorted(n * 4) {
		init(v, 0, n - 1, 1);
	}

	int query(int i, int j, int k)
	{
		return query(i - 1, j - 1, k, 1, 0, n - 1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N;
	vector<int> v(N);
	for (auto& x : v)
		cin >> x;
	RMQ rmq(v);
	cin >> M;
	int prev = 0;
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		prev = rmq.query(a ^ prev, b ^ prev, c ^ prev);
		cout << prev << '\n';
	}
}
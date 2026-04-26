// 116ms, 11800KB

#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

struct Segtree {
	int n;
	vector<ll> rangeSum;
	vector<ll> lazyI, lazyD;

	Segtree(vector<int>& org) : n(org.size() - 1), rangeSum(org.size() * 4), lazyI(org.size() * 4), lazyD(org.size() * 4) {
		init(org, 1, 1, n);
	}

	void update(int l, int r) {
		update_range(1, 1, n, l, r);
	}

	ll query(int pos) {
		return query(1, 1, n, 1, pos) - query(1, 1, n, 1, pos - 1);
	}

private:
	void init(vector<int>& org, int node, int l, int r) {
		if (l == r) {
			rangeSum[node] = org[l];
		}
		else {
			int mid = (l + r) >> 1;
			init(org, node << 1, l, mid);
			init(org, 1 + (node << 1), mid + 1, r);
			rangeSum[node] = rangeSum[node << 1] + rangeSum[1 + (node << 1)];
		}
	}

	void update_lazy(int node, int start, int end) {
		if (lazyD[node] == 0)
			return;

		int len = end - start + 1;
		rangeSum[node] += (2LL * lazyI[node] + lazyD[node] * (ll)(end - start)) * len / 2LL;
		
		if (start != end) {
			int nl = node << 1;
			int nr = nl + 1;
			lazyI[nl] += lazyI[node];
			lazyD[nl] += lazyD[node];
			lazyI[nr] += lazyI[node] + (len + 1) / 2 * lazyD[node];
			lazyD[nr] += lazyD[node];
		}

		lazyI[node] = 0;
		lazyD[node] = 0;
	}
	
	void update_range(int node, int start, int end, int l, int r) {
		update_lazy(node, start, end);
		if (l > end || r < start)
			return;

		int childL = node << 1;
		int childR = childL + 1;
		int mid = (start + end) / 2;
		
		if (l <= start && end <= r) {
			rangeSum[node] += ((ll)start + end - 2LL * l + 2LL) * (ll)(end - start + 1) / 2;
			if (start != end) {
				lazyI[childL] += start - l + 1;
				lazyI[childR] += start - l + 1 + (end - start + 2) / 2;
				++lazyD[childL];
				++lazyD[childR];
			}
			return;
		}

		update_range(childL, start, mid, l, r);
		update_range(childR, mid + 1, end, l, r);
		rangeSum[node] = rangeSum[childL] + rangeSum[childR];
	}

	ll query(int node, int start, int end, int l, int r) {
		update_lazy(node, start, end);
		if (l > end || r < start || l > r)
			return 0;
		if (l <= start && end <= r)
			return rangeSum[node];
		int mid = (start + end) >> 1;
		ll lSum = query(node << 1, start, mid, l, r);
		ll rSum = query(1 + (node << 1), mid + 1, end, l, r);
		return lSum + rSum;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	vector<int> arr;

	cin >> N;
	arr.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	Segtree st(arr);

	int Q;
	for (cin >> Q; ~--Q;) {
		int op, a, b;
		cin >> op >> a;
		if (op == 1) {
			cin >> b;
			st.update(a, b);
		}
		else {
			cout << st.query(a) << '\n';
		}
	}
}
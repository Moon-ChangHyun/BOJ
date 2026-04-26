// 80ms, 7580KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

class segTree {
	int n;
	vector<ll> rangeSum;

	ll init(const vector<int>& arr, int node, int nodeL, int nodeR) {
		if (nodeL == nodeR)
			return rangeSum[node] = arr[nodeL];

		int childL = node << 1;
		int childR = childL + 1;
		int mid = (nodeL + nodeR) >> 1;

		return rangeSum[node] = 
			init(arr, childL, nodeL, mid) + init(arr, childR, mid + 1, nodeR);
	}

	int update(int idx, int val, int node, int nodeL, int nodeR) {
		if (idx < nodeL || nodeR < idx) return 0;
		if (nodeL == nodeR) {
			int org = rangeSum[node];
			rangeSum[node] = val;
			return val - org;
		}
		int childL = node << 1;
		int childR = childL + 1;
		int mid = (nodeL + nodeR) >> 1;

		int delta = update(idx, val, childL, nodeL, mid) + update(idx, val, childR, mid + 1, nodeR);
		rangeSum[node] += delta;
		return delta;
	}

	ll query(int l, int r, int node, int nodeL, int nodeR) {
		if (nodeR < l || r < nodeL)
			return 0;
		if (l <= nodeL && nodeR <= r)
			return rangeSum[node];

		int childL = node << 1;
		int childR = childL + 1;
		int mid = (nodeL + nodeR) >> 1;

		return query(l, r, childL, nodeL, mid) + query(l, r, childR, mid + 1, nodeR);
	}

public:
	segTree(const vector<int>& arr) : n(arr.size()), rangeSum(arr.size() * 4) {
		init(arr, 1, 0, n - 1);
	}

	void update(pair<int,int> param) {
		update(param.first, param.second, 1, 0, n - 1);
	}

	ll query(pair<int,int> range) {
		return query(range.first, range.second, 1, 0, n - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	int N, M;
	vector<pair<int, int>> query1List;
	vector<pair<int, pair<int, int>>> query2List;
	vector<int> orderQuery2;
	vector<ll> ans;
	cin >> N;
	vector<int> arr(N);
	for (auto& x : arr)
		cin >> x;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int op, a, b, c;
		cin >> op >> a >> b;
		if (op == 1) {
			query1List.emplace_back(a - 1, b);
		}
		else {
			cin >> c;
			query2List.emplace_back(a, pair<int, int>{b - 1, c - 1});
		}
	}

	ans.resize(query2List.size());
	orderQuery2.resize(query2List.size());
	for (int i = 0; i < orderQuery2.size(); ++i)
		orderQuery2[i] = i;
	sort(orderQuery2.begin(), orderQuery2.end(), [&query2List](int a, int b) {
		return query2List[a].first < query2List[b].first;
	});

	segTree st(arr);

	int idxQ1 = 0;
	for (int i = 0; i < orderQuery2.size(); ++i) {
		int idxQ2 = orderQuery2[i];
		auto& q2 = query2List[idxQ2];
		for (; idxQ1 < q2.first; ++idxQ1) {
			auto& q1 = query1List[idxQ1];
			st.update(q1);
		}
		ans[idxQ2] = st.query(q2.second);
	}

	for (auto& x : ans)
		cout << x << '\n';
}
// 108ms, 4032KB

#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int N, K;

struct SegTree {
	vector<int> rangeCnt;
	void update(int nd, int ndL, int ndR, int num, bool isPlus) {
		if (num < ndL || ndR < num) return;
		if (isPlus)
			++rangeCnt[nd];
		else
			--rangeCnt[nd];
		if (ndL == ndR) return;
		int childL = nd << 1;
		int childR = childL + 1;
		int mid = (ndL + ndR) >> 1;
		update(childL, ndL, mid, num, isPlus);
		update(childR, mid + 1, ndR, num, isPlus);
	}
	int query(int nd, int ndL, int ndR, int idx) {
		if (ndL == ndR) 
			return ndL;
		int childL = nd << 1;
		int childR = childL + 1;
		int mid = (ndL + ndR) >> 1;
		if (idx > rangeCnt[childL])
			return query(childR, mid + 1, ndR, idx - rangeCnt[childL]);
		return query(childL, ndL, mid, idx);
	}

public:
	SegTree() : rangeCnt(4 * 65536) {
	}
	void add(int num) {
		update(1, 0, 65536, num, true);
	}
	void remove(int num) {
		update(1, 0, 65536, num, false);
	}
	int query() {
		//assert: rangeCnt[1] = K;
		return query(1, 0, 65536, (K + 1) >> 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	ll ans = 0;
	SegTree st;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		st.add(arr[i]);
		if (i >= K)
			st.remove(arr[i - K]);
		if (i >= K - 1)
			ans += st.query();
	}
	cout << ans;
}
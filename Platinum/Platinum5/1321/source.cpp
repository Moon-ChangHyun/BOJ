// 48ms, 11796KB

#include<iostream>
#include<vector>

using namespace std;

class segTree {
	int N;
	vector<int> tree;
	int init(const vector<int>& initVec, int l, int r, int nd) {
		if (l == r) {
			return tree[nd] = initVec[l];
		}
		int mid = (l + r) >> 1;
		int lSum = init(initVec, l, mid, nd << 1);
		int rSum = init(initVec, mid + 1, r, (nd << 1) + 1);
		return tree[nd] = lSum + rSum;
	}
	void updateSquad(int nd, int ndL, int ndR, int squad, int delta) {
		if (squad < ndL || ndR < squad) return;
		tree[nd] += delta;
		if (ndL == ndR) return;
		int mid = (ndL + ndR) >> 1;
		updateSquad(nd << 1, ndL, mid, squad, delta);
		updateSquad((nd << 1) + 1, mid + 1, ndR, squad, delta);
	}
	int findSquad(int nd, int ndL, int ndR, int num) {
		//assert: tree[nd] >= num
		if (ndL == ndR) return ndL;
		int childL = nd << 1;
		int childR = childL + 1;
		int mid = (ndL + ndR) >> 1;
		if (tree[childL] < num)
			return findSquad(childR, mid + 1, ndR, num - tree[childL]);
		return findSquad(childL, ndL, mid, num);
	}
public:
	segTree(const vector<int>& initVec) : N(initVec.size()), tree(4 * initVec.size()) {
		init(initVec, 0, N - 1, 1);
	}
	void updateSquad(int squad, int delta) {
		updateSquad(1, 0, N - 1, squad - 1, delta);
	}
	int findSquad(int num) {
		return findSquad(1, 0, N - 1, num) + 1;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N;
	vector<int> arr(N);
	for (auto& x : arr)
		cin >> x;
	
	segTree st(arr);

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int op, a, b;
		cin >> op >> a;
		if (op == 1) {
			cin >> b;
			st.updateSquad(a, b);
		}
		else {
			cout << st.findSquad(a) << '\n';
		}
	}
}
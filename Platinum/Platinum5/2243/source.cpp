// 80ms, 5928KB

#include<iostream>
#include<vector>
using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {}
	// 1 base
	int sum(int pos) {
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}
	void add(int pos, int val) {
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
	int pick(int order) {
		int lo = 0, hi = 1000000;
		while (lo + 1 != hi) {
			int mid = (lo + hi) >> 1;
			if (sum(mid) >= order) hi = mid;
			else lo = mid;
		}
		add(hi, -1);
		return hi;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	FenwickTree ft(1000000);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b;
		if (a == 1) {
			cout << ft.pick(b) << '\n';
		}
		else {
			cin >> c;
			ft.add(b, c);
		}
	}
}
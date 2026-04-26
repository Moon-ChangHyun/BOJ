// 48ms, 2804KB

#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

struct FenwickTree {
	vector<ll> tree;
	FenwickTree(int n) : tree(n + 1) {}
	void update(int pos, ll val) {
		while (pos > 0) {
			tree[pos] += val;
			pos &= (pos - 1);
		}
	}
	ll query(int pos) {
		ll ret = 0;
		while (pos < tree.size()) {
			ret += tree[pos];
			pos += (pos & -pos);
		}
		return ret;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, a, b;
	ll k;
	cin >> N;
	FenwickTree ft(N);
	for (int i = 1; i <= N; ++i)
	{
		cin >> k;
		ft.update(i, k);
		ft.update(i - 1, -k);
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> b >> a;
		if (b & 1)
		{
			cin >> b >> k;
			ft.update(b, k);
			ft.update(a - 1, -k);
		}
		else
			cout << ft.query(a) << '\n';
	}
}
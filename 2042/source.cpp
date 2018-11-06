#include <iostream>
#include <vector>
using namespace std;
class fenwickTree {
public:
	fenwickTree(int n) : tree(n + 1) {}
	long long sum(int pos) {
		++pos;
		long long ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}
	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
private:
	std::vector<long long> tree;
};
int N, M, K;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	auto ft = fenwickTree(N);
	for (int i = 0; i != N; ++i) {
		int x;
		cin >> x;
		ft.add(i, x);
	}
	for (int i = M + K; i != 0; --i) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 1)
			ft.add(a - 1, b - (ft.sum(a - 1) - ft.sum(a - 2)));
		else
			cout << ft.sum(b - 1) - ft.sum(a - 2) << '\n';
	}
}
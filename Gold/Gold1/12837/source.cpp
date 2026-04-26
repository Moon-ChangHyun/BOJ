// 48ms, 9748KB

#include<cstdio>
#include<vector>
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
int main() {
	int n, q, a, b, c;
	scanf("%d%d", &n, &q);
	auto ft = fenwickTree(n);
	for (int i = 0; i != q; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1)
			ft.add(b - 1, c);
		else
			printf("%lld\n", ft.sum(c - 1) - ft.sum(b - 2));
	}
}
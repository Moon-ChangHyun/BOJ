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
	int n, m, a, b, c;
	scanf("%d%d", &n, &m);
	fenwickTree ft(n + 1);
	for (int i = 0; i != m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		if (a)
			ft.add(b, c - (ft.sum(b) - ft.sum(b - 1)));
		else {
			if (c < b) {
				c ^= b;
				b ^= c;
				c ^= b;
			}
			printf("%lld\n", ft.sum(c) - ft.sum(b - 1));
		}
	}
}
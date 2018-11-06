#include<cstdio>
#include<vector>
using namespace std;

class RSQ {
private:
	int n;
	vector<long long> rangeSum;
	long long init(const vector<int>& arr, int left, int right, int node) {
		if (left == right)
			return rangeSum[node] = arr[left];
		int mid = (left + right) >> 1;
		return rangeSum[node] = init(arr, left, mid, node << 1) + init(arr, mid + 1, right, (node << 1) + 1);
	}
	long long query(int left, int right, int node, int lookUpLeft, int lookUpRight) {
		if (left > lookUpRight || right < lookUpLeft)
			return 0;
		if (left <= lookUpLeft && lookUpRight <= right)
			return rangeSum[node];
		int lookUpMid = (lookUpLeft + lookUpRight) >> 1;
		return query(left, right, node << 1, lookUpLeft, lookUpMid) + query(left, right, (node << 1) + 1, lookUpMid + 1, lookUpRight);
	}
	long long update(int index, int newVal, int node, int lookUpLeft, int lookUpRight) {
		if (index < lookUpLeft || lookUpRight < index)
			return rangeSum[node];
		if (lookUpLeft == lookUpRight)
			return rangeSum[node] = newVal;
		int lookUpMid = (lookUpLeft + lookUpRight) >> 1;
		return rangeSum[node] = update(index, newVal, node << 1, lookUpLeft, lookUpMid) + update(index, newVal, (node << 1) + 1, lookUpMid + 1, lookUpRight);
	}
public:
	RSQ(const vector<int>& arr) {
		n = arr.size();
		rangeSum.resize(4 * n);
		init(arr, 0, n - 1, 1);
	}
	long long query(int left, int right) {
		return query(left - 1, right - 1, 1, 0, n - 1);
	}
	long long update(int seq, int newVal) {
		return update(seq - 1, newVal, 1, 0, n - 1);
	}
};

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> v(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	RSQ rsq(v);
	for (int i = 0; i != q; ++i) {
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		printf("%lld\n", x < y ? rsq.query(x, y) : rsq.query(y, x));
		rsq.update(a, b);
	}
}
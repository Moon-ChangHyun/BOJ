// 188ms, 21492KB

#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
#define MOD 1000000007;
using namespace std;
class RMQ {
private:
	static const int intMax = numeric_limits<int>::max();
	int n;
	vector<int> rangeMul;
	int init(const vector<int>& arr, int left, int right, int node) {
		if (left == right)
			return rangeMul[node] = arr[left] % MOD;
		int mid = (left + right) >> 1;
		return rangeMul[node] = ((long long)init(arr, left, mid, node << 1) * (long long)init(arr, mid + 1, right, (node << 1) + 1)) % MOD;
	}
	int _query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || left > nodeRight)
			return 1;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMul[node];
		int mid = (nodeLeft + nodeRight) >> 1;
		return ((long long)_query(left, right, node << 1, nodeLeft, mid) * (long long)_query(left, right, (node << 1) + 1, mid + 1, nodeRight)) % MOD;
	}
	int _update(int index, int newVal, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index)
			return rangeMul[node];
		if (nodeLeft == nodeRight)
			return rangeMul[node] = newVal;
		int mid = (nodeLeft + nodeRight) >> 1;
		return rangeMul[node] =
			((long long)_update(index, newVal, node << 1, nodeLeft, mid) * (long long)_update(index, newVal, (node << 1) + 1, mid + 1, nodeRight)) % MOD;
	}
public:
	RMQ(const vector<int>& arr) {
		n = arr.size();
		rangeMul.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
	int query(int left, int right) {
		return _query(left - 1, right - 1, 1, 0, n - 1);
	}
	int update(int index, int newVal) {
		return _update(index - 1, newVal, 1, 0, n - 1);
	}
};

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<int> v(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	RMQ rmq(v);
	for (int i = m + k; ~--i;) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a == 1 ? rmq.update(b, c) : printf("%d\n", rmq.query(b, c));
	}
}
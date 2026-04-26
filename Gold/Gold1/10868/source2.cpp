// 100ms, 3196KB

#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class RMQ {
private:
	static const int intMax = numeric_limits<int>::max();
	int n;
	vector<int> rangeMin;
	int init(const vector<int>& arr, int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = arr[left];
		int mid = (left + right) >> 1;
		return rangeMin[node] = 
			min(init(arr, left, mid, node << 1), init(arr, mid + 1, right, (node << 1) + 1));
	}
	int _query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || left > nodeRight)
			return intMax;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		int mid = (nodeLeft + nodeRight) >> 1;
		return min(_query(left, right, node << 1, nodeLeft, mid), _query(left, right, (node << 1) + 1, mid + 1, nodeRight));
	}
public:
	RMQ(const vector<int>& arr) {
		n = arr.size();
		rangeMin.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
	int query(int left, int right) {
		return _query(left - 1, right - 1, 1, 0, n - 1);
	}
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> v(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	RMQ rmq(v);
	for (int i = 0; i != m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", rmq.query(a, b));
	}
}
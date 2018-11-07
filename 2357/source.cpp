#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class RMQ {
private:
	static const int intMin = numeric_limits<int>::min();
	static const int intMax = numeric_limits<int>::max();
	int n;
	vector<int> rangeMin;
	vector<int> rangeMax;
	pair<int, int> init(const vector<int>& arr, int left, int right, int node) {
		if (left == right) {
			rangeMin[node] = rangeMax[node] = arr[left];
			return{ rangeMin[node], rangeMax[node] };
		}
		int mid = (left + right) >> 1;
		pair<int, int> leftMinMax = init(arr, left, mid, node << 1);
		pair<int, int> rightMinMax = init(arr, mid + 1, right, (node << 1) + 1);
		rangeMin[node] = min(leftMinMax.first, rightMinMax.first);
		rangeMax[node] = max(leftMinMax.second, rightMinMax.second);
		return{ rangeMin[node], rangeMax[node] };
	}
	pair<int, int> _query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || left > nodeRight)
			return{ intMax, intMin };
		if (left <= nodeLeft && nodeRight <= right)
			return{ rangeMin[node], rangeMax[node] };
		int mid = (nodeLeft + nodeRight) >> 1;
		pair<int, int> leftMinMax = _query(left, right, node << 1, nodeLeft, mid);
		pair<int, int> rightMinMax = _query(left, right, (node << 1) + 1, mid + 1, nodeRight);
		return{ min(leftMinMax.first, rightMinMax.first), max(leftMinMax.second, rightMinMax.second) };
	}
public:
	RMQ(const vector<int>& arr) {
		n = arr.size();
		rangeMin.resize(n * 4);
		rangeMax.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
	pair<int, int> query(int left, int right) {
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
		auto ans = rmq.query(a, b);
		printf("%d %d\n", ans.first, ans.second);
	}
}
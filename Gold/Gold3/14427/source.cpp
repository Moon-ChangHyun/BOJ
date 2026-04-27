// 48ms, 3976KB

#include<iostream>
#include<vector>
using namespace std;

struct RMQ {
	int n;
	vector<int> values, rangeMinIdx;
	RMQ(vector<int>&& src) : values(move(src)) {
		n = values.size();
		rangeMinIdx.resize(n << 2);
		values[0] = 1000000001;
		init(1, n - 1, 1);
	}
	int init(int left, int right, int node) {
		if (left == right)
			return rangeMinIdx[node] = left;
		int mid = (left + right) >> 1;
		int leftMinIdx = init(left, mid, node << 1);
		int rightMinIdx = init(mid + 1, right, (node << 1) + 1);
		return rangeMinIdx[node] = (values[leftMinIdx] <= values[rightMinIdx] ? leftMinIdx : rightMinIdx);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return 0;
		if (left <= nodeLeft && nodeRight <= right) return rangeMinIdx[node];
		int mid = (nodeLeft + nodeRight) >> 1;
		int leftMinIdx = query(left, right, node << 1, nodeLeft, mid);
		int rightMinIdx = query(left, right, (node << 1) + 1, mid + 1, nodeRight);
		return (values[leftMinIdx] <= values[rightMinIdx]) ? leftMinIdx : rightMinIdx;
	}
	int query(int left, int right) {
		return query(left, right, 1, 1, n - 1);
	}
	void update(int idx, int node, int nodeLeft, int nodeRight) {
		if (nodeLeft == nodeRight || idx < nodeLeft || nodeRight < idx) return;
		int leftNode = node << 1;
		int rightNode = leftNode + 1;
		int mid = (nodeLeft + nodeRight) >> 1;
		update(idx, leftNode, nodeLeft, mid);
		update(idx, rightNode, mid + 1, nodeRight);
		rangeMinIdx[node] = (values[rangeMinIdx[leftNode]] <= values[rangeMinIdx[rightNode]]) ? rangeMinIdx[leftNode] : rangeMinIdx[rightNode];
	}
	void update(int idx, int newValue) {
		values[idx] = newValue;
		update(idx, 1, 1, n - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;
	vector<int> data(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> data[i];
	auto rmq = RMQ(move(data));
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a;
		if (a & 1) {
            cin >> b >> c;
			rmq.update(b , c);
		}
		else {
			cout << rmq.query(1, N) << '\n';
		}
	}
}
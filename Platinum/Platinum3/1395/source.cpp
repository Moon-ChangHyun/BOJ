// 92ms, 3724KB

#include<vector>
#include<iostream>
using namespace std;

class RFQ {
private:
	int n;
	vector<int> rangeFlag;
	vector<bool> haveToUpdate;
	void _lazyUpdate(int node, int len) {
		rangeFlag[node] = len - rangeFlag[node];
		haveToUpdate[node] = false;
		int leftNodeNum = node << 1;
		int rightNodeNum = leftNodeNum + 1;
		if (len > 1) {
			haveToUpdate[leftNodeNum] = !haveToUpdate[leftNodeNum];
			haveToUpdate[rightNodeNum] = !haveToUpdate[rightNodeNum];
		}
	}
	void _toggle(int left, int right, int node, int nodeLeft, int nodeRight) {
		int len = nodeRight + 1 - nodeLeft;
		int leftNodeNum = node << 1;
		int rightNodeNum = leftNodeNum + 1;
		if (haveToUpdate[node])
			_lazyUpdate(node, len);
		if (right < nodeLeft || left > nodeRight) return;
		if (left <= nodeLeft && nodeRight <= right) {
			haveToUpdate[node] = !haveToUpdate[node];
			_lazyUpdate(node, len);
			return;
		}
		int mid = (nodeLeft + nodeRight) >> 1;
		_toggle(left, right, leftNodeNum, nodeLeft, mid);
		_toggle(left, right, rightNodeNum, mid + 1, nodeRight);
		rangeFlag[node] = rangeFlag[leftNodeNum] + rangeFlag[rightNodeNum];
	}
	int _query(int left, int right, int node, int nodeLeft, int nodeRight) {
		int len = nodeRight + 1 - nodeLeft;
		int leftNodeNum = node << 1;
		int rightNodeNum = leftNodeNum + 1;
		if (haveToUpdate[node])
			_lazyUpdate(node, len);
		if (right < nodeLeft || left > nodeRight) return 0;
		if (left <= nodeLeft && nodeRight <= right) return rangeFlag[node];
		int mid = (nodeLeft + nodeRight) >> 1;
		return _query(left, right, leftNodeNum, nodeLeft, mid) + _query(left, right, rightNodeNum, mid + 1, nodeRight);
	}
public:
	RFQ(int size) {
		n = size;
		rangeFlag.resize(n * 4, 0);
		haveToUpdate.resize(n * 4, false);
	}
	int query(int left, int right) {
		return _query(left - 1, right - 1, 1, 0, n - 1);
	}
	void toggle(int left, int right) {
		_toggle(left - 1, right - 1, 1, 0, n - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	auto rfq = RFQ(N);
	for (int i = 0; i != M; ++i) {
		int O, S, T;
		cin >> O >> S >> T;
		if (O) {
			cout << rfq.query(S, T) << '\n';
		}
		else {
			rfq.toggle(S, T);
		}
	}
}
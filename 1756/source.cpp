#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int D, N;
	cin >> D >> N;
	vector<int> minSize(D + 1);
	minSize[0] = 1234567891;
	for (int i = 1; i <= D; ++i) {
		int x;
		cin >> x;
		minSize[i] = min(minSize[i - 1], x);
	}
	int lowest = D + 1;
	for (int i = 0; i != N; ++i) {
		int x;
		cin >> x;
		auto iter = upper_bound(minSize.begin(), minSize.end(), x, greater<>());
		int pos = distance(minSize.begin(), iter) - 1;
		lowest = min(lowest - 1, pos);
	}
	cout << (lowest <= 0 ? 0 : lowest);
}
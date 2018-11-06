#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, C;
vector<int> data;
bool func(int d) {
	int remain = C - 1;
	int prev = data[0];
	for (int i = 1; i != N; ++i) {
		if (data[i] - prev >= d) {
			prev = data[i];
			--remain;
		}
		if (!remain) break;
	}
	return remain == 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> C;
	data.resize(N);
	for (int i = 0; i != N; ++i)
		cin >> data[i];
	sort(data.begin(), data.end());
	int lo = 1, hi = data.back() - data.front();
	while (lo + 1 != hi) {
		int mid = (lo + hi) >> 1;
		if (func(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo;
}
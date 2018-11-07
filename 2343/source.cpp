#include<iostream>
using namespace std;
int N, M;
short v[100000];
bool func(int x) {
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i != N; ++i) {
		if (v[i] > x) return false;
		sum += v[i];
		if (sum > x) {
			++cnt;
			sum = v[i];
		}
	}
	if (sum != 0) ++cnt;
	return cnt <= M;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int lo = 0, hi = 0;
	cin >> N >> M;
	for (int i = 0; i != N; ++i) {
		cin >> v[i];
		hi += v[i];
	}
	while (lo + 1 != hi) {
		int mid = (lo + hi) >> 1;
		if (func(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi;
}
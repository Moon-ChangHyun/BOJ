#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> jewelrys;

bool func(int max) {
	int needPerson = 0;
	for (auto iter : jewelrys)
		needPerson += iter / max + (iter % max ? 1 : 0);
	return needPerson <= n;
}

int main() {
	int lo = 0, hi = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	jewelrys.resize(m);
	for (int i = 0; i != m; ++i) {
		cin >> jewelrys[i];
		hi = jewelrys[i] > hi ? jewelrys[i] : hi;
	}
	while (lo + 1 != hi) {
		int mid = (lo + hi) >> 1;
		if (func(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;
}
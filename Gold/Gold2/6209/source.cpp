// 12ms, 2220KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int d, n, m;
vector<int> stone;

bool func(int k) { //거리최솟값이 k이상이라면 m개를 제거 가능한가?
	int prev = 0, removed = 0;
	for (int i = 0; i < n; ++i) {
		if (removed == m) {
			if (stone[i] - prev < k)
				return false;
			prev = stone[i];
		}
		else {
			if (stone[i] - prev < k)
				++removed;
			else 
				prev = stone[i];
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> d >> n >> m;
	stone.resize(n);
	for (auto& val : stone)
		cin >> val;
	sort(stone.begin(), stone.end());
	int lo = 0, hi = d + 1;
	while (lo + 1 != hi) {
		int mid = (lo + hi) >> 1;
		if (func(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo;
}
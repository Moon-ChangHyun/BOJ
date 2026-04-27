// 8ms, 2260KB

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	int N, K, S;
	cin >> N >> K >> S;
	vector<pair<int, int>> v(N); // <위치, 수>
	for (auto& x : v)
		cin >> x.first >> x.second;
	
	sort(v.begin(), v.end());
	int l = 0, r = N - 1;
	int school = lower_bound(v.begin(), v.end(), pair<int,int>{ S, 0 }) - v.begin();

	int ans = 0;
	while (school <= r) {
		int cnt = 0;
		int i = r;
		for (; school <= i; --i) {
			cnt += v[i].second;
			v[i].second = 0;
			if (cnt > K) {
				v[i].second = cnt - K;
				cnt = K;
				break;
			}
		}
		ans += 2 * (v[r].first - S);
		r = i;
	}

	while (l < school) {
		int cnt = 0;
		int i = l;
		for (; i < school; ++i) {
			cnt += v[i].second;
			v[i].second = 0;
			if (cnt > K) {
				v[i].second = cnt - K;
				cnt = K;
				break;
			}
		}
		ans += 2 * (S - v[l].first);
		l = i;
	}
	cout << ans;
}
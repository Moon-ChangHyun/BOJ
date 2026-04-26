// 560ms, 2020KB

#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	while (true) {
		cin >> n >> m;
		if (n + m == 0) break;
		if (n < m) swap(n, m);
		ll ans = 0;
		for (int k = 1; k <= m; k += 2) {
			ll boxCnt = (ll)(m - k + 1) * (n - k + 1);
			ans += boxCnt * k;
		}
		cout << ans << '\n';
	}
}
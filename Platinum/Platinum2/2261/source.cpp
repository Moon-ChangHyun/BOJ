// 60ms, 3208KB

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int f(int l, int r) {
	if (l + 1 == r) return 987654321;
	if (l + 2 == r) {
		int dx = v[l].first - v[l + 1].first;
		int dy = v[l].second - v[l + 1].second;
		return dx * dx + dy * dy;
	}
	int m = (l + r) >> 1;
	int lx = f(l, m), rx = f(m, r);
	int d = min(lx, rx);
	double sqrtD = sqrt(d);
	int searchStart = upper_bound(v.begin() + l, v.begin() + m, pair<int, int>{ ceil(v[m].first - sqrtD), -10001 }) - v.begin();
	int searchEnd = upper_bound(v.begin() + m, v.begin() + r, pair<int, int>{floor(v[m].first + sqrtD), 10001}) - v.begin();
	vector<pair<int, int>> mids;
	int midsSize = searchEnd - searchStart;
	mids.resize(midsSize);
	copy(v.begin() + searchStart, v.begin() + searchEnd, mids.begin());
	sort(mids.begin(), mids.end(),
		[](const pair<int, int>& a, const pair<int, int>& b) {
			if (a.second < b.second) return true;
			if (a.second > b.second) return false;
			return a.first < b.first;
		});
	for (int i = 0; i < midsSize; ++i) {
		for (int j = i + 1; j < midsSize; ++j) {
			int mdy = mids[i].second - mids[j].second;
			mdy *= mdy;
			if (mdy >= d) break;
			int mdx = mids[i].first - mids[j].first;
			mdx *= mdx;
			d = min(d, mdx + mdy);
		}
	}
	return d;
}
int main() {
	int n, x, y;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i != n; ++i)
		scanf("%d%d", &v[i].first, &v[i].second);
	sort(v.begin(), v.end());
	printf("%d", f(0, v.size()));
}
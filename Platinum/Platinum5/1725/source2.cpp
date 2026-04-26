// 20ms, 1620KB

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int f(vector<int>& v, int s, int e) {
	if (e - s == 1) return v[s];
	int maxS = max(f(v, s, (s + e) / 2), f(v, (s + e) / 2, e));
	int mh, ms, me;
	me = 1 + (s + e) / 2;
	ms = me - 2;
	mh = min(v[ms], v[me-1]);
	maxS = max(mh * 2, maxS);
	while (s < ms || me < e) {
		if (me < e && (ms == s || v[ms - 1] < v[me])) {
			++me;
			mh = min(mh, v[me - 1]);
		}
		else {
			--ms;
			mh = min(mh, v[ms]);
		}
		maxS = max(maxS, mh*(me - ms));
	}
	return maxS;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v;
    v.reserve(n);
	int h;
	for (int i = 0; i != n; ++i) {
		scanf("%d", &h);
		v.push_back(h);
	}
	printf("%d\n", f(v, 0, n));
}
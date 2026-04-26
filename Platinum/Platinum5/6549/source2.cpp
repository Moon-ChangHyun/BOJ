// 68ms, 1628KB

#include<cstdio>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		vector<int> heights(n);
		for (int i = 0; i != n; ++i)
			scanf("%d", &heights[i]);
		function<long long(int, int)> f = [&f, &heights](int lo, int hi) {
			if (lo == hi)
				return (long long)heights[lo];
			int mid = (lo + hi) >> 1;
			long long ret = max(f(lo, mid), f(mid + 1, hi));
			int left = mid, right = mid + 1;
			int height = min(heights[left], heights[right]);
			ret = max(ret, (long long)height * 2);
			while (lo < left || right < hi) {
				if (right < hi && (left == lo || heights[left - 1] < heights[right + 1])) {
					++right;
					height = min(height, heights[right]);
				}
				else {
					--left;
					height = min(height, heights[left]);
				}
				ret = max(ret, (long long)height * (right - left + 1));
			}
			return ret;
		};
		printf("%lld\n", f(0, n - 1));
	}
}
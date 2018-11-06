#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, M, ret = 0;
	scanf("%d%d", &N, &M);
	vector<int> v(N);
	for (int i = 0; i != N; ++i)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	int lo = 0, hi = N - 1;
	while (lo != hi) {
		int sum = v[lo] + v[hi];
		if (sum == M) {
			++ret;
			++lo;
		}
		else if (sum < M)
			++lo;
		else
			--hi;
	}
	printf("%d", ret);
}
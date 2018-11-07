#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int n;
	long long ret = 0;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i != n; ++i) scanf("%d", &v[i]);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			int x = v[i] - v[j];
			ret += (x > 0 ? x : -x) << 1;
		}
	printf("%lld", ret);
}
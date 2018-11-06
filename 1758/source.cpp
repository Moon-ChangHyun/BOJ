#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end(), greater<>());
	long long ret = 0;
	for (int i = 0; i != n && ((v[i] -= i) > 0); ++i)
		ret += v[i];
	printf("%lld", ret);
}
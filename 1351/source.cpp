#include<cstdio>
#include<vector>
using namespace std;
long long N, P, Q;
vector<long long> v(1000001, 0);
long long getA(long long num) {
	if (num > 1000000)
		return getA(num / P) + getA(num / Q);
	long long& ret = v[num];
	if (ret) return ret;
	return ret = getA(num / P) + getA(num / Q);
}
int main() {
	v[0] = 1;
	scanf("%lld%lld%lld", &N, &P, &Q);
	printf("%lld", getA(N));
}
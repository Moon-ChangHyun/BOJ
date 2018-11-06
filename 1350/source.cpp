#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int N, t, M;
	long long r = 0;
	scanf("%d", &N);
	vector<int> v(N);
	for (auto& iter : v)
		scanf("%d", &iter);
	scanf("%d", &M);
	for (auto& iter : v) {
		double d = iter;
		r += ceil(d / M);
	}
	printf("%lld", r*M);
}
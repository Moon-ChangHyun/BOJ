#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int N;
	double pmul = 1, ret = 0;
	scanf("%d", &N);
	for (int i = 0; i != N; ++i) {
		double x;
		scanf("%lf", &x);
		pmul = max(1.0, pmul) * x;
		ret = max(ret, pmul);
	}
	printf("%.3f", ret);
}
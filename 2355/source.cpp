#include <cstdio>
#include <cmath>
int main() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%d", (int)((std::abs(a - b) + 1) * (a + b) / 2));
}
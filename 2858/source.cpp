#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int R, B;
	scanf("%d%d", &R, &B);
	int sum = (R + 4) / 2;
	int mul = R + B;
	int L = (sum + (int)sqrt(sum * sum - 4 * mul)) / 2;
	int W = sum - L;
	if (L < W) {
		L ^= W;
		W ^= L;
		L ^= W;
	}
	printf("%d %d", L, W);
}
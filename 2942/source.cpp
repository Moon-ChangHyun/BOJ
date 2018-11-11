#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int R, G, A;
	scanf("%d%d", &R, &G);
	if (R < G) A = gcd(R, G);
	else A = gcd(G, R);
	//printf("%d", A);
	int rootA = (int)sqrt(A);
	for (int i = 1; i <= rootA; ++i) {
		if (A % i == 0) {
			printf("%d %d %d\n", i, R / i, G / i);
			if (i * i != A) {
				int j = A / i;
				printf("%d %d %d\n", j, R / j, G / j);
			}
		}
	}
}
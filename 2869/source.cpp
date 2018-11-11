#include<cstdio>
#include<cmath>
int main() {
	int a, b, v;
	scanf("%d%d%d", &a, &b, &v);
	double d = (v - b) / (double)(a - b);
	printf("%d", (int)ceil(d));
}
#include<cstdio>
#include<cmath>
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (b >= c) printf("-1");
	else printf("%d", (int)(1 + (a / (double)(c - b))));
}
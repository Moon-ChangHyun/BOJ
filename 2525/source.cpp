#include<cstdio>
int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	b += c;
	a += b / 60;
	printf("%d %d", a % 24, b % 60);
}
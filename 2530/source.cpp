#include <cstdio>
int main() {
	int A, B, C, D;
	int a, b, c;
	scanf("%d%d%d%d", &A, &B, &C, &D);
	B += (C + D) / 60;
	c = (C + D) % 60;
	A += B / 60;
	b = B % 60;
	a = A % 24;
	printf("%d %d %d", a, b, c);
}
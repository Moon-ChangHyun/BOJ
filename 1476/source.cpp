#include <iostream>
int main() {
	int e, s, m;
	scanf("%d%d%d", &e, &s, &m);
	int num = e;
	s %= 28;
	m %= 19;
	while (s != num % 28 || m != num % 19)
		num += 15;
	printf("%d", num);
}
#include <iostream>
#include <cmath>
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int l = ceil(sqrt((double)m));
	int h = floor(sqrt((double)n));
	if (l > h) printf("%d", -1);
	else {
		int sum = 0;
		for (int i = l; i != h + 1; ++i)
			sum += i * i;
		printf("%d\n%d", sum, l*l);
	}
}
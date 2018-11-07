#include<cstdio>
int main() {
	int num = 0, max = 0, x;
	for (int i = 0; i != 4; ++i) {
		scanf("%d", &x);
		num -= x;
		max = max > num ? max : num;
		scanf("%d", &x);
		num += x;
		max = max > num ? max : num;
	}
	printf("%d", max);
}
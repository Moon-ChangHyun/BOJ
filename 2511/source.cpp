#include<cstdio>
int main() {
	int a[10], b[10], as = 0, bs = 0;
	for (int i = 0; i != 10; ++i) scanf("%d", a + i);
	for (int i = 0; i != 10; ++i) {
		scanf("%d", b + i);
		if (a[i] > b[i]) as += 3;
		else if (a[i] < b[i]) bs += 3;
		else {
			as += 1;
			bs += 1;
		}
	}
	printf("%d %d\n", as, bs);
	if (as > bs)
		printf("A");
	else if (as < bs)
		printf("B");
	else {
		int i = 9;
		for (; i != -1; --i) {
			if (a[i] > b[i]) {
				printf("A");
				break;
			}
			else if (a[i] < b[i]) {
				printf("B");
				break;
			}
		}
		if (i == -1)
			printf("D");
	}
}
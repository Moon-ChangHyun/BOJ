#include<cstdio>
int main() {
	int N, F;
	scanf("%d%d", &N, &F);
	N /= 100;
	N *= 100;
	for (int i = 0; i != 100; ++i) {
		if (((N + i) % F) == 0) {
			if (i < 10)
				printf("0");
			printf("%d", i);
			break;
		}
	}
}
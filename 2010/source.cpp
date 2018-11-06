#include<cstdio>
int main() {
	int N, t, S = 1;
	scanf("%d", &N);
	for (int i = 0; i != N; ++i) {
		scanf("%d", &t);
		S += t;
	}
	printf("%d", S - N);
}
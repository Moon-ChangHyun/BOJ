#include <cstdio>
int f[41] = {0, 1};
int main() {
    for(int i = 2; i <= 40; ++i)
        f[i] = f[i - 2] + f[i - 1];
	int T;
	for (scanf("%d", &T); ~--T;) {
		int num;
		scanf("%d", &num);
		printf("%d %d\n", num ? f[num - 1] : 1, f[num]);
	}
}
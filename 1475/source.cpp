#include <cstdio>
char n;
int digit[9];
int main() {
	while (n != '\n') {
		scanf("%c", &n);
		if (n == '9') ++digit[6];
		else ++digit[n - '0'];
	}
	digit[6] = (digit[6] + 1) / 2;
	int ans = 0;
	for (int i = 0; i != 9; ++i) ans = ans > digit[i] ? ans : digit[i];
	printf("%d", ans);
}
#include<cstdio>
int main() {
	char c[101];
	scanf("%s", c);
	for (int i = 0; c[i]; ++i) {
		if (c[i] >= 'a') c[i] -= 32;
		else c[i] += 32;
	}
	printf("%s", c);
}
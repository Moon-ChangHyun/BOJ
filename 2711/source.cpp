#include<cstdio>
int main() {
	int T;
	for (scanf("%d", &T); ~--T; ) {
		int p;
		char str[81];
		scanf("%d%s", &p, str);
		str[p - 1] = 's';
		for (int i = 0; str[i]; ++i) {
			if (str[i] != 's')
				printf("%c", str[i]);
		}
		printf("\n");
	}
}
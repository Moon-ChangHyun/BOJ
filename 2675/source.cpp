#include<cstdio>
int main() {
	int t;
	for (scanf("%d", &t); ~--t;) {
		int r;
		char str[21];
		scanf("%d%s", &r, str);
		for (int i = 0; str[i]; ++i)
			for (int j = 0; j != r; ++j)
				printf("%c", str[i]);
		printf("\n");
	}
}
#include<cstdio>
int main() {
	int ret = 0;
	char a, b;
	for (int i = 0; i != 8; ++i) {
		for (int j = 0; j != 4; ++j) {
			scanf(" %c%c", &a, &b);
			if (i % 2) {
				if (b == 'F')
					++ret;
			}
			else {
				if (a == 'F')
					++ret;
			}
		}
	}
	printf("%d", ret);
}
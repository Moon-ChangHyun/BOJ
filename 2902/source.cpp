#include<cstdio>
int main() {
	char c;
	printf("%c", getchar());
	while ((c = getchar()) != '\n') {
		if (c == 45) {
			printf("%c", getchar());
		}
	}
}
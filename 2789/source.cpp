#include<cstdio>
int main() {
	char voca[101];
	scanf("%s", voca);
	for (int i = 0; voca[i]; ++i) {
		char c = voca[i];
		if (c != 'C' && c != 'A' && c != 'M' && c != 'B' && c != 'R' && c != 'I' && c != 'D' && c != 'G' && c != 'E')
			printf("%c", c);
	}
}
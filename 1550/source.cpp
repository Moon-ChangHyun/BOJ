#include<cstdio>
int f(char c) {
	if (c <= '9')
		return c - '0';
	else
		return (c - 'A') + 10;
}
int main() {
	int ret = 0;
	char in[7];
	scanf("%s", in);
	for (int i = 0; in[i]; ++i) {
		ret *= 16;
		ret += f(in[i]);
	}
	printf("%d", ret);
}
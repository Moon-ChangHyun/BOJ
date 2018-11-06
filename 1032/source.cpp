#include<cstdio>
int main() {
	char str[50][51];
	int n;
	scanf("%d", &n);
	scanf("%s", str[0]);
	for (int i = 1; i < n; ++i) {
		scanf("%s", str[i]);
		for (int j = 0; str[i][j]; ++j) {
			if (str[i][j] != str[0][j])
				str[0][j] = '?';
		}
	}
	printf("%s", str[0]);
}
#include<cstdio>
char* enc[8]{ "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };
int main() {
	bool b = true;
	int n, idx = 0;
	char str[61], ret[11];
	scanf("%d%s", &n, str);
	for (int i = 0; str[i]; i += 6) {
		int missMatch = 0;
		for (int j = 0; j != 8; ++j) {
			int errorCnt = 0;
			for (int k = 0; k != 6; ++k)
				errorCnt += enc[j][k] != str[i + k];
			if (errorCnt <= 1) {
				ret[idx++] = 'A' + j;
				break;
			}
			else
				++missMatch;
		}
		if (missMatch == 8) {
			printf("%d", idx + 1);
			b = false;
			break;
		}
	}
	if (b) {
		ret[idx] = 0;
		printf("%s", ret);
	}
}
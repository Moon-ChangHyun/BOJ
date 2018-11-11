#include<cstdio>
int main() {
	char A[31], B[31];
	int a, b;
	bool find = false;
	scanf("%s %s", A, B);
	for (a = 0; A[a]; ++a) {
		for (b = 0; B[b]; ++b) {
			if (A[a] == B[b]) {
				find = true;
				break;
			}
		}
		if (find) break;
	}
	for (int i = 0; B[i]; ++i) {
		for (int j = 0; A[j]; ++j) {
			if (i == b) printf("%c", A[j]);
			else if (j == a) printf("%c", B[i]);
			else printf(".");
		}
		printf("\n");
	}
}
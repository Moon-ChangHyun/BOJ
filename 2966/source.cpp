#include<cstdio>
char S[3] = { 'A', 'B', 'C' };
char C[4] = { 'B', 'A', 'B', 'C' };
char H[6] = { 'C', 'C', 'A', 'A', 'B', 'B' };

int main() {
	int N, scoreS = 0, scoreC = 0, scoreH = 0;
	scanf("%d", &N);
	for (int i = 0; i != N; ++i) {
		char ans;
		scanf(" %c", &ans);
		if (S[i % 3] == ans) ++scoreS;
		if (C[i % 4] == ans) ++scoreC;
		if (H[i % 6] == ans) ++scoreH;
	}
	if (scoreS > scoreC) {
		if (scoreS > scoreH)
			printf("%d\nAdrian", scoreS);
		else if (scoreS == scoreH)
			printf("%d\nAdrian\nGoran", scoreS);
		else
			printf("%d\nGoran", scoreH);

	}
	else if (scoreS == scoreC) {
		if (scoreS > scoreH)
			printf("%d\nAdrian\nBruno", scoreS);
		else if (scoreS == scoreH)
			printf("%d\nAdrian\nBruno\nGoran", scoreS);
		else
			printf("%d\nGoran", scoreH);
	}
	else {
		if (scoreC > scoreH)
			printf("%d\nBruno", scoreC);
		else if (scoreC == scoreH)
			printf("%d\nBruno\nGoran", scoreC);
		else
			printf("%d\nGoran", scoreH);
	}
}
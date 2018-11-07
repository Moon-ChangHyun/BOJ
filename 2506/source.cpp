#include<cstdio>
int main() {
	int n, x, partScore = 0, totalScore = 0;
	bool b = false;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &x);
		if (x) {
			b = true;
			totalScore += ++partScore;
		}
		else {
			b = false;
			partScore = 0;
		}
	}
	printf("%d", totalScore);
}
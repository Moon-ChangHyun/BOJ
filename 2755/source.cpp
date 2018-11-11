#include<cstdio>
int main() {
	int N, totalWeight = 0;
	double totalScore = 0.0;
	for (scanf("%d", &N); ~--N; ) {
		char name[101];
		int weight;
		double score;
		char scoreTmp;
		scanf("%s%d %c", name, &weight, &scoreTmp);
		totalWeight += weight;
		if (scoreTmp == 'F')
			score = 0.0;
		else {
			switch (scoreTmp) {
			case 'A':
				score = 4.0;
				break;
			case 'B':
				score = 3.0;
				break;
			case 'C':
				score = 2.0;
				break;
			case 'D':
				score = 1.0;
			}
			scanf("%c", &scoreTmp);
			if (scoreTmp == '+') score += 0.3;
			else if (scoreTmp == '-')score -= 0.3;
		}
		totalScore += score * weight;
	}
	double ret = totalScore / totalWeight;
	ret *= 100;
	ret = (int)(ret + 0.5);
	ret /= 100;
	printf("%.2f", ret);
}
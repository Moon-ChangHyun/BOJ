#include<cstdio>

int getPartSum(int num) {
	int ret = num;
	while (num) {
		ret += num % 10;
		num /= 10;
	}
	return ret;
}

int main() {
	int N, ret = 0;
	scanf("%d", &N);
	for (int i = 1; i != N; ++i) {
		if (N == getPartSum(i)) {
			ret = i;
			break;
		}
	}
	printf("%d", ret);
}
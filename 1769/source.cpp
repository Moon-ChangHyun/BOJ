#include<cstdio>
inline int func(int num) {
	int sum = 0;
	while (num) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int main() {
	char num[1000001];
	scanf("%s", num);
	int ret = 0;
	if (!num[1]) {
		printf("0\n");
		if (num[0] == '3' || num[0] == '6' || num[0] == '9') printf("YES");
		else printf("NO");
	}
	else {
		int x = 0;
		for (int i = 0; num[i]; ++i)
			x += (num[i] & 15);
		++ret;
		while (x / 10) {
			x = func(x);
			++ret;
		}
		printf("%d\n", ret);
		if (x == 3 || x == 6 || x == 9) printf("YES");
		else printf("NO");
	}
}
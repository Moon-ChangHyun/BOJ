#include<cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if (a == 1 || a == 5)
		printf("%lld", a - 1 + 8L * b);
	else {
		long long ret = a - 1 + 8L * (b >> 1);
		if (b % 2) {
			switch (a) {
			case 2:
				ret += 2;
			case 3:
				ret += 2;
			case 4:
				ret += 2;
			}
		}
		printf("%lld", ret);
	}
}
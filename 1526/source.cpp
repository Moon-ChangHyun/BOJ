#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	int ret = n;
	while (true) {
		bool b = true;
		int k = ret;
		while (k) {
			if (k % 10 != 4 && k % 10 != 7) {
				b = false;
				break;
			}
			k /= 10;
		}
		if (b)
			break;
		else
			--ret;

	}
	printf("%d", ret);
}
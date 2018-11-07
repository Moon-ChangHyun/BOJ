#include<cstdio>
int main() {
	int mx = 0, p = 0;
	for (int i = 0; i != 10; ++i) {
		int a;
		scanf("%d", &a);
		p -= a;
		scanf("%d", &a);
		p += a;
		mx = mx > p ? mx : p;
	}
	printf("%d", mx);
}
#include<cstdio>
int main() {
	int X, Y;
	scanf("%d%d", &X, &Y);
	double ret = 1000 * X / (double)Y;
	int N;
	for (scanf("%d", &N); ~--N; ) {
		int x, y;
		scanf("%d%d", &x, &y);
		double price = 1000 * x / (double)y;
		ret = price < ret ? price : ret;
	}
	printf("%.2lf", ret);
}
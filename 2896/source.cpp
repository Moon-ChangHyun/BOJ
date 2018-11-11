#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int a, b, c, i, j, k;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &i, &j, &k);
	double ratio = min(min(a / (double)i, b / (double)j), c / (double)k);
	printf("%f %f %f", a - ratio * i, b - ratio * j, c - ratio * k);
}
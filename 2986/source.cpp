#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int n, i;
	scanf("%d", &n);
	int rootN = sqrt(n);
	for (i = 2; i <= rootN; ++i)
		if (n % i == 0) break;
	if (i > rootN)
		printf("%d", n - 1);
	else {
		i = n / i;
		printf("%d", n - i);
	}
}
#include<cstdio>
#include<functional>
#include<algorithm>

using namespace std;

int k, n;
unsigned int cables[10000];

bool f(unsigned int l) {
	int num = 0;
	for (int i = 0; i != k; ++i) {
		num += cables[i] / l;
		if (num >= n) return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i != k; ++i)
		scanf("%d", cables + i);
	sort(cables, cables + k, greater<unsigned int>());
	unsigned int a = 1, b = cables[0] + 1; // half open : <= <
	while (a + 1 != b) {
		unsigned int c = (a + b) >> 1;
		f(c) ? a = c : b = c;
	}
	printf("%d", a);
}
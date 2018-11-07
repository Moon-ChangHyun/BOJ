#include<cstdio>
#include<array>
#include<bitset>
using namespace std;
array<bitset<2187>, 2187> arr;
void f(int n, int y, int x) {
	if (n == 1) {
		arr[y][x] = true;
		return;
	}
	n /= 3;
	f(n, y, x);
	f(n, y, x + n);
	f(n, y, x + 2 * n);
	f(n, y + n, x);
	f(n, y + n, x + 2 * n);
	f(n, y + 2 * n, x);
	f(n, y + 2 * n, x + n);
	f(n, y + 2 * n, x + 2 * n);
}
int main() {
	int n;
	scanf("%d", &n);
	f(n, 0, 0);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != n; ++j)
			printf("%c", arr[i][j] ? '*' : ' ');
		printf("\n");
	}
}
#include<cstdio>
#include<cmath>
using namespace std;

int n, cnt[8001]; //bias +4000

double f1() {
	int x = 0;
	for (int i = 0; i != 8001; ++i)
		x += cnt[i] * (i - 4000);
	return (double)x / n;
}

int f2() {
	int cri = n / 2;
	int num = 0;
	for (int i = 0; i != 8001; ++i) {
		num += cnt[i];
		if (num > cri) {
			return i - 4000;
		}
	}
	return 987654321;
}

int f3() {
	int first = 0;
	for (int i = 0; i != 8001; ++i) {
		if (cnt[i] > cnt[first])
			first = i;
	}
	for (int i = first + 1; i < 8001; ++i) {
		if (cnt[first] == cnt[i])
			return i - 4000;
	}
	return first - 4000;
}

int f4() {
	int mn = 0, mx = 8000;
	while (!cnt[mn])++mn;
	while (!cnt[mx])--mx;
	return mx - mn;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x + 4000];
	}
	printf("%d\n", int(floor(f1() + 0.5)));
	printf("%d\n", f2());
	printf("%d\n", f3());
	printf("%d\n", f4());
}
#include<iostream>
using namespace std;
int main() {
	int n, x, max = 0, s = 0;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &x);
		max = x > max ? x : max;
		s += x;
	}
	double ret = s * 100 / double(max) / n;
	cout.precision(2);
	cout << fixed << ret;
}
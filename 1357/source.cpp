#include <iostream>
int main() {
	int x = 0, y = 0, r = 0;
	char ax[5] = { 0 }, ay[5] = { 0 }, ar[5] = { 0 };
	scanf("%s %s", ax, ay);
	for (int i = 3; i != -1; --i) {
		if (ax[i] == 0) continue;
		x *= 10;
		x += ax[i] - '0';
	}
	for (int i = 3; i != -1; --i) {
		if (ay[i] == 0) continue;
		y *= 10;
		y += ay[i] - '0';
	}
	r = x + y;
	while (!(r % 10)) r /= 10;
	for (int i = 0; i != 5; ++i) {
		if (r == 0) break;
		ar[i] = '0' + (r % 10);
		r /= 10;
	}
	printf("%s", ar);
}
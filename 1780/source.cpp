#include<cstdio>
int arr[2187][2187];
int ret[3];
void f(int y, int x, int size) {
	int tmp = arr[y][x];
	bool b = true;
	for (int i = y; i != y + size; ++i)
		for (int j = x; j != x + size; ++j)
			if (tmp != arr[i][j]) {
				b = false;
				break;
			}
	if (b) {
		++ret[tmp + 1];
		return;
	}
	tmp = size / 3;
	f(y, x, tmp);
	f(y, x + tmp, tmp);
	f(y, x + (tmp << 1), tmp);
	f(y + tmp, x, tmp);
	f(y + tmp, x + tmp, tmp);
	f(y + tmp, x + (tmp << 1), tmp);
	f(y + (tmp << 1), x, tmp);
	f(y + (tmp << 1), x + tmp, tmp);
	f(y + (tmp << 1), x + (tmp << 1), tmp);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			scanf("%d", &arr[i][j]);
	f(0, 0, n);
	printf("%d\n%d\n%d", ret[0], ret[1], ret[2]);
}
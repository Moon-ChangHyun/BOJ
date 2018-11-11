#include<cstdio>
#include<bitset>
#include<array>
using namespace std;
array<bitset<128>, 128> v;
pair<int, int> f(int y, int x, int size) {
	bool first = v[y][x];
	bool same = true;
	for (int i = y; i != y + size; ++i) {
		for (int j = x; j != x + size; ++j) {
			if (first ^ v[i][j]) {
				same = false;
				break;
			}
		}
	}
	if (same)
		return { first == false, first == true };
	pair<int, int> ret = { 0, 0 };
	auto tmp = f(y, x, size / 2);
	ret.first += tmp.first;
	ret.second += tmp.second;
	tmp = f(y, x + size / 2, size / 2);
	ret.first += tmp.first;
	ret.second += tmp.second;
	tmp = f(y + size / 2, x, size / 2);
	ret.first += tmp.first;
	ret.second += tmp.second;
	tmp = f(y + size / 2, x + size / 2, size / 2);
	ret.first += tmp.first;
	ret.second += tmp.second;
	return move(ret);
}
int main() {
	int n;
	char t;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != n; ++j) {
			scanf(" %c", &t);
			v[i][j] = (t == '1');
		}
	}
	auto ret = f(0, 0, n);
	printf("%d\n%d", ret.first, ret.second);
}
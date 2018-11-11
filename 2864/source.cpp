#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int min = 0, max = 0, minS = 0, maxS = 0;
	for (int i = 0; i != a.size(); ++i) {
		min *= 10;
		max *= 10;
		if (a[i] == '5') max += 1;
		else if (a[i] == '6') min -= 1;
		min += a[i] - '0';
		max += a[i] - '0';
	}
	minS = min;
	maxS = max;
	min = max = 0;
	for (int i = 0; i != b.size(); ++i) {
		min *= 10;
		max *= 10;
		if (b[i] == '5') max += 1;
		else if (b[i] == '6') min -= 1;
		min += b[i] - '0';
		max += b[i] - '0';
	}
	printf("%d %d", minS + min, maxS + max);
}
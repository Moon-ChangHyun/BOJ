#include <iostream>
using namespace std;
unsigned long long cache[88][2] = { 0 };
unsigned long long prinary(int n, bool pre) {
	if (n < 1) return 1;
	unsigned long long& ret = cache[n][pre];
	if (ret)
		return ret;
	ret = prinary(n - 1, 0);
	if (!pre)
		ret += prinary(n - 1, 1);
	return ret;
}
int main() {
	int n;
	cin >> n;
	cout << prinary(n - 2, 0);
}
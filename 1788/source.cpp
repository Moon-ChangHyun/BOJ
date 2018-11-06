#define MOD 1000000000
#include<cstdio>
#include<array>
using namespace std;
array<array<long long, 2>, 2> operator*(array<array<long long, 2>, 2>& a, array<array<long long, 2>, 2>& b) {
	array<array<long long, 2>, 2> ret;
	for (int i = 0; i != 2; ++i)
		for (int j = 0; j != 2; ++j)
			ret[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
	return move(ret);
}
array<array<long long, 2>, 2> operator*(array<array<long long, 2>, 2>& a, array<array<long long, 2>, 2>&& b) {
	array<array<long long, 2>, 2> ret;
	for (int i = 0; i != 2; ++i)
		for (int j = 0; j != 2; ++j)
			ret[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
	return move(ret);
}
array<array<long long, 2>, 2> power(array<array<long long, 2>, 2>& mat, long long exp) {
	array<array<long long, 2>, 2> tmp = { {{1, 0}, {0, 1}} };
	if (exp == 0) return move(tmp);
	if (exp % 2) return mat * power(mat, exp - 1);
	tmp = power(mat, exp >> 1);
	return tmp * tmp;
}
int main() {
	int sgn = 1;
	long long n;
	scanf("%lld", &n);
	array<array<long long, 2>, 2> def = { {{1, 1}, {1, 0}} };
	if (n == 0) {
		printf("0\n0");
	}
	else {
		if (n < 0) {
			n = -n;
			if (n % 2 == 0)
				sgn = -1;
		}
		printf("%d\n", sgn);
		printf("%lld", power(def, n - 1)[0][0]);
	}
}
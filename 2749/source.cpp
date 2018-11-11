#include<cstdio>
#include<array>
#include<memory>
#define MOD 1000000
using namespace std;
using Matrix = array<array<long long, 2>, 2>;

Matrix operator*(Matrix& a, Matrix& b) {
	Matrix ret;
	for (int i = 0; i != 2; ++i)
		for (int j = 0; j != 2; ++j)
			ret[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
	return move(ret);
}
Matrix operator*(Matrix& a, Matrix&& b) {
	Matrix ret;
	for (int i = 0; i != 2; ++i)
		for (int j = 0; j != 2; ++j)
			ret[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
	return move(ret);
}

Matrix power(Matrix& mat, long long exp) {
	Matrix tmp = { {{1, 0}, {0, 1}} };
	if (exp == 0) return move(tmp);
	if (exp & 1) return mat * power(mat, exp - 1);
	tmp = power(mat, exp >> 1);
	return tmp * tmp;
}
int main() {
	long long n;
	scanf("%lld", &n);
	Matrix def = { {{1, 1}, {1, 0}} };
	printf("%lld", power(def, n - 1)[0][0]);
}
// 0ms, 1116KB

#include<cstdio>
#include<array>
#define MOD 1000000007LL
using namespace std;
using MAT = array<array<int, 4>, 4>;

MAT wMat = {{{0, 1, 2, 0},{1, 0, 0, 0},{1, 0, 0, 1},{0, 0, 1, 0}}};
MAT base = {{{1, 0, 0, 0},{0, 1, 0, 0},{0, 0, 1, 0},{0, 0, 0, 1}}};

MAT matMul(MAT& aMat, MAT& bMat) {
	MAT ret;
	for(int i = 0; i != 4; ++i) {
		for(int j = 0; j != 4; ++j) {
			ret[i][j] = 0;
			for(int k = 0; k != 4; ++k)
				ret[i][j] = (ret[i][j] + ((long long)aMat[i][k] * bMat[k][j]) % MOD) % MOD;
		}
	}
	return ret;
}

MAT power(MAT& mat, long long n) {
	if(n == 0)
		return base;
	if(n & 1) {
		MAT tmp = power(mat, n - 1);
		return matMul(tmp, mat);
	}
	else {
		MAT half = power(mat, n >> 1);
		return matMul(half, half);
	}
}

int main() {
	long long n;
	scanf("%lld", &n);
	MAT ret = power(wMat, n);
	printf("%d", (ret[1][1] + ret[1][2]) % MOD);
}
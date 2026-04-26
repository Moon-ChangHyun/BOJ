// 0ms, 1228KB

#include<cstdio>
#include<vector>
using namespace std;
static constexpr int MOD = 1000000007;
struct Mat8x8 {
	Mat8x8() : data(8, vector<int>(8)){
	}
	Mat8x8(vector<vector<int>> && src) : data(move(src)) {}
	vector<vector<int>> data;
	const vector<int>& operator[](int i) const {
		return data[i];
	}
	
};
Mat8x8 operator* (const Mat8x8& lhs, const Mat8x8& rhs) {
	Mat8x8 ret;
	for (int i = 0; i != 8; ++i)
		for (int j = 0; j != 8; ++j)
			for (int k = 0; k != 8; ++k)
				ret.data[i][j] = (ret[i][j] + ((long long)lhs[i][k] * rhs[k][j]) % MOD) % MOD;
	return ret;
}
Mat8x8 pow(const Mat8x8& lhs, int n) {
	if (n == 0)
		return Mat8x8{ {{1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1}} };
	if (n & 1)
		return pow(lhs, n - 1) * lhs;
	else {
		auto half = pow(lhs, n >> 1);
		return half * half;
	}
}
Mat8x8 xMat = { { {0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1, 0}, {0, 0, 0, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0} } };

int func(int D) {
	return pow(xMat, D)[0][0];
}

int main() {
	int D;
	scanf("%d", &D);
	printf("%d", func(D));
}
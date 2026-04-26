// 0ms, 1116KB

#include<cstdio>
#include<algorithm>
#include<initializer_list>

using namespace std;
constexpr int MOD = 1'000'000'007;
struct Matrix22
{
	int val[4];
	Matrix22() : val{ 1, 0, 0, 1 } {}
	Matrix22(initializer_list<int> iList) 
	{
		if (iList.size() != 4) return;
		int idx = 0;
		for (auto i : iList)
			val[idx++] = i;
	}
};
Matrix22 operator*(const Matrix22& lhs, const Matrix22& rhs)
{
	Matrix22 ret;
	ret.val[0] = (((long long)lhs.val[0] * rhs.val[0]) % MOD + ((long long)lhs.val[1] * rhs.val[2]) % MOD) % MOD;
	ret.val[1] = (((long long)lhs.val[0] * rhs.val[1]) % MOD + ((long long)lhs.val[1] * rhs.val[3]) % MOD) % MOD;
	ret.val[2] = (((long long)lhs.val[2] * rhs.val[0]) % MOD + ((long long)lhs.val[3] * rhs.val[2]) % MOD) % MOD;
	ret.val[3] = (((long long)lhs.val[2] * rhs.val[1]) % MOD + ((long long)lhs.val[3] * rhs.val[3]) % MOD) % MOD;
	return ret;
}
template <typename T>
T genericPow(const T& t, long long int exp)
{
	if (!exp) return T();
	if (exp & 1) return t * genericPow(t, exp - 1);
	T half = genericPow(t, exp >> 1);
	return half * half;
}

int main()
{
	long long int n;
	scanf("%lld", &n);
	Matrix22 mat {0, 1, 1, 1};
	printf("%d", genericPow(mat, n).val[1]);
}
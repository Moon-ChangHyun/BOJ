// 380ms, 158272KB

#include<iostream>
using namespace std;

const long long P = 1000000007;
int fact[40000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    fact[0] = 1;
	for (long long i = 1; i <= 40000000; ++i)
		fact[i] = fact[i - 1] * i % P;
	int M;
	for (cin >> M; ~--M;)
	{
		int N, K;
		cin >> N >> K;
		long long A = fact[N], B = (long long)fact[N - K] * fact[K] % P, C = P - 2, ret = 1;
		while (C) {
			if (C & 1) ret = ret * B % P;
			B = B * B % P;
			C >>= 1;
		}
		cout << (A * ret % P) << '\n';
	}
}
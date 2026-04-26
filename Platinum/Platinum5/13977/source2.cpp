// 112ms, 17644KB

#include<iostream>
using namespace std;

constexpr int P = 1000000007;
int fact[4000001];

int pow(int a, int b) {
	if (b == 0) return 1;
	if (b & 1) return ((long long)a * pow(a, b - 1)) % P;
	long long half = pow(a, b >> 1);
	return (half * half) % P;
}

int getCombi(int N, int K) {
	return ((long long)fact[N] * pow((int)(((long long)fact[N - K] * fact[K]) % P), P - 2)) % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = 1;
	for (int i = 1; i <= 4000000; ++i)
		fact[i] = (fact[i - 1] * (long long)i) % P;
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int N, K;
		cin >> N >> K;
		cout << getCombi(N, K) << '\n';
	}
}
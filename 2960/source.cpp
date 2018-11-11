#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int N, K;
vector<bool> notPrime;
int main() {
	scanf("%d%d", &N, &K);
	notPrime.resize(N + 1, false);
	notPrime[0] = notPrime[1] = true;
	for (int i = 2; i <= N; ++i) {
		for (int j = i; j <= N; j += i) {
			if (notPrime[j]) continue;
			notPrime[j] = true;
			--K;
			if (!K) {
				printf("%d", j);
				break;
			}
		}
		if (!K) break;
	}
}
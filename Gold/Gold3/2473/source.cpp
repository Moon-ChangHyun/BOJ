// 28ms, 1116KB

#include<cstdio>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
	int N, arr[5000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", arr + i);
	sort(arr, arr + N);
	int ansA = 0, ansB = 1, ansC = N - 1;
	ll ansSumABS = abs(arr[ansA] + arr[ansB] + (ll)arr[ansC]);
	for (int c = 2; c < N; ++c) {
		int a = 0, b = c - 1;
		int bestA = a, bestB = b;
		ll bestSumABS = abs(arr[bestA] + arr[bestB] + (ll)arr[c]);
		while (a < b) {
			ll sum = arr[a] + arr[b] + (ll)arr[c];
			if (abs(sum) < bestSumABS) {
				bestSumABS = abs(sum);
				bestA = a;
				bestB = b;
			}
			if (sum == 0) {
				printf("%d %d %d", arr[a], arr[b], arr[c]);
				return 0;
			}
			else if (sum > 0) {
				--b;
			}
			else {
				++a;
			}
		}
		if (bestSumABS < ansSumABS) {
			ansSumABS = bestSumABS;
			ansA = bestA;
			ansB = bestB;
			ansC = c;
		}
	}
	printf("%d %d %d", arr[ansA], arr[ansB], arr[ansC]);
}
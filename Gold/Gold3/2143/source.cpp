// 516ms, 42280KB

#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int main() {
	int T, N, M;
	long long ret = 0;
	scanf("%d%d", &T, &N);
	vector<int> arrA(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &arrA[i]);
		arrA[i] += arrA[i - 1];
	}
	scanf("%d", &M);
	vector<int> arrB(M + 1, 0);
	for (int i = 1; i <= M; ++i) {
		scanf("%d", &arrB[i]);
		arrB[i] += arrB[i - 1];
	}
	map<int, int> m; //부분합, 개수
	if (N > M) {
		//arrB를 전처리
		for (int end = 1; end <= M; ++end) {
			for (int start = 0; start < end; ++start) {
				++m[arrB[end] - arrB[start]];
			}
		}
		for (int end = 1; end <= N; ++end) {
			for (int start = 0; start < end; ++start) {
				int tmp = arrA[end] - arrA[start];
				ret += m[T - tmp];
			}
		}
	}
	else {
		//arrA를 전처리
		for (int end = 1; end <= N; ++end) {
			for (int start = 0; start < end; ++start) {
				++m[arrA[end] - arrA[start]];
			}
		}
		for (int end = 1; end <= M; ++end) {
			for (int start = 0; start < end; ++start) {
				int tmp = arrB[end] - arrB[start];
				ret += m[T - tmp];
			}
		}
	}
	printf("%lld", ret);
}
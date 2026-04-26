// 6972ms, 99608KB

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N;
	long long ret = 0;
	scanf("%d", &N);
	vector<int> A(N), B(N), C(N), D(N), K;
	for (int i = 0; i != N; ++i) {
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
	}
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != N; ++j) {
			K.push_back(A[i] + B[j]);
		}
	}
	sort(K.begin(), K.end());
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != N; ++j) {
			int target = -(C[i] + D[j]);
			auto lb = lower_bound(K.begin(), K.end(), target);
			if (lb != K.end() && *lb == target) {
				auto ub = upper_bound(K.begin(), K.end(), target);
				ret += ub - lb;
			}
		}
	}
	printf("%lld", ret);
}
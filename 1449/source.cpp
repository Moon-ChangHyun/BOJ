#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N, L, ret = 0, lastP;
	scanf("%d%d", &N, &L);
	vector<int> v(N);
	for (int i = 0; i != N; ++i)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	lastP = v[0];
	for (int i = 1; i < N; ++i) {
		if (v[i] - lastP > L - 1) {
			++ret;
			lastP = v[i];
		}
	}
	printf("%d", ++ret);
}
#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int N, ret = 0;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i != N; ++i)
		scanf("%d", &v[i]);
	for (int i = N - 1; i; --i) {
		if (v[i - 1] >= v[i]) {
			ret += v[i - 1] - v[i] + 1;
			v[i - 1] = v[i] - 1;
		}
	}
	printf("%d", ret);
}
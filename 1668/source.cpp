#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i != N; ++i)
		scanf("%d", &v[i]);
	int ret = 1, last = 0;
	for (int i = 1; i < N; ++i) {
		if (v[last] < v[i]) {
			++ret;
			last = i;
		}
	}
	printf("%d\n", ret);
	ret = 1, last = N - 1;
	for (int i = N - 1; ~--i; ) {
		if (v[last] < v[i]) {
			++ret;
			last = i;
		}
	}
	printf("%d", ret);

}
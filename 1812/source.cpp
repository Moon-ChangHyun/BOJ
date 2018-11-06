#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int N, minIdx = 0;
	scanf("%d", &N);
	vector<int> v(N), candy(N);
	for (int i = 0; i != N; ++i) {
		scanf("%d", &v[i]);
		if (v[minIdx] > v[i])
			minIdx = i;
	}
	int endIdx = (minIdx + N - 1) % N;
	for (int iv = 0; iv <= v[minIdx]; ++iv) {
		candy[minIdx] = iv;
		int nextVal = v[minIdx] - iv;
		int idx = (minIdx + 1) % N;
		for (; idx != minIdx; idx = (idx + 1) % N) {
			candy[idx] = nextVal;
			nextVal = v[idx] - nextVal;
			if (nextVal < 0) break;
		}
		if (idx == minIdx && candy[minIdx] == nextVal)
			break;
	}
	for (int i = 0; i != N; ++i)
		printf("%d\n", candy[i]);
}
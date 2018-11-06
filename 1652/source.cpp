#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<vector<char>> v(N, vector<char>(N));
	for (int i = 0; i != N; ++i)
		for (int j = 0; j != N; ++j)
			scanf(" %c", &v[i][j]);
	int ret = 0;
	for (int i = 0; i != N; ++i) {
		int len = 0;
		for (int j = 0; j != N; ++j) {
			if (v[i][j] == 'X') {
				if (len >= 2)
					++ret;
				len = 0;
			}
			else
				++len;
		}
		if (len >= 2) ++ret;
	}
	printf("%d ", ret);
	ret = 0;
	for (int j = 0; j != N; ++j) {
		int len = 0;
		for (int i = 0; i != N; ++i) {
			if (v[i][j] == 'X') {
				if (len >= 2)
					++ret;
				len = 0;
			}
			else
				++len;
		}
		if (len >= 2) ++ret;
	}
	printf("%d", ret);
}
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, ret, arr[1000][1000];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != m; ++j) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j])
				ret = 1;
		}
	}
	for (int i = 1; i != n; ++i) {
		for (int j = 1; j != m; ++j) {
			if (arr[i][j] && arr[i - 1][j - 1]) {
				int l = arr[i - 1][j - 1];
				int end = i - l;
				int a = i - 1;
				for (; a >= end; --a)
					if (arr[a][j] == 0)
						break;
				a = i - a;
				int b = j - 1;
				for (end = j - l; b >= end; --b)
					if (arr[i][b] == 0)
						break;
				b = j - b;
				arr[i][j] = min(a, b);
				ret = max(ret, arr[i][j]);
			}
		}
	}
	printf("%d", ret * ret);
}
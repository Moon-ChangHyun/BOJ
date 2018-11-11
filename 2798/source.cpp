#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int n, m, ret = 0;
	scanf("%d%d", &n, &m);
	vector<int> v(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	for (int i = 0; i < n - 2; ++i)
		for (int j = i + 1; j < n - 1; ++j)
			for (int k = j + 1; k < n; ++k) {
				int sum = v[i] + v[j] + v[k];
				if (sum <= m)
					ret = ret < sum ? sum : ret;
			}
	printf("%d", ret);
}
#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int n, x;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &x);
		for (int j = i; j != i - x; --j)
			v[j] = v[j - 1];
		v[i - x] = i + 1;
	}
	for (auto iter : v)
		printf("%d ", iter);
}
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int ret = 0;
	for (auto& iter : v) {
		ret = max(ret, (iter * n--));
	}
	printf("%d", ret);
}
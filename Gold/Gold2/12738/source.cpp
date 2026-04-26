// 272ms, 11292KB

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
vector<int> lis;
int main() {
	int n;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	lis.push_back(v[0]);
	for (int i = 1; i != v.size(); ++i) {
		if (lis.back() < v[i])
			lis.push_back(v[i]);
		else {
			auto iter = lower_bound(lis.begin(), lis.end(), v[i]);
			*iter = v[i];
		}
	}
	printf("%d", lis.size());
}
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int x, s = 0;
	vector<int> v;
	for (int i = 0; i != 7; ++i) {
		scanf("%d", &x);
		if (x % 2) {
			v.push_back(x);
			s += x;
		}
	}
	sort(v.begin(), v.end());
	if (v.empty()) printf("-1");
	else printf("%d\n%d", s, v[0]);
}
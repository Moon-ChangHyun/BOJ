#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int x, s = 0;
	vector<int> v;
	for (int i = 0; i != 5; ++i) {
		scanf("%d", &x);
		v.push_back(x);
		s += x;
	}
	sort(v.begin(), v.end());
	printf("%d\n%d", s / 5, v[2]);
}
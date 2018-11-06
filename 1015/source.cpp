#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	set<pair<int, int>> s;
	vector<int> v;
	for (int i = 0; i != n; ++i) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	    s.insert({ x, i });
	}
	for (int i = 0; i != n; ++i)
		printf("%d ", distance(s.begin(), s.find({v[i], i})));
}
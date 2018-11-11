#include<cstdio>
#include<map>
#include<set>
using namespace std;
int main() {
	int t, s = 0;
	map<int, int> m;
	for (int i = 1; i <= 8; ++i) {
		scanf("%d", &t);
		m.insert({ t, i });
	}
	set<int> r;
	for (auto iter = next(m.begin(), 3); iter != m.end(); ++iter) {
		r.insert(iter->second);
		s += iter->first;
	}
	printf("%d\n", s);
	for (auto& iter : r)
		printf("%d ", iter);
}
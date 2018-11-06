#include<cstdio>
#include<list>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	list<int> ls;
	for (int i = 1; i <= n; ++i)
		ls.push_back(i);
	int ret = 0;
	auto iter = ls.begin();
	for (int i = 0; i != m; ++i) {
		int x;
		scanf("%d", &x);
		int a = 0;
		while (*iter != x) {
			++a;
			if (++iter == ls.end())
				iter = ls.begin();
		}
		if (a != 0) {
			if (2 * a <= ls.size()) {
				ret += a;
			}
			else {
				ret += ls.size() - a;
			}
		}
		auto eIter = iter;
		if (++iter == ls.end())
			iter = ls.begin();
		ls.erase(eIter);
	}
	printf("%d", ret);
}
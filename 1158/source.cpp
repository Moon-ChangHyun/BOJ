#include<cstdio>
#include<list>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	list<int> list;
	for (int i = 1; i <= n; ++i) list.push_back(i);
	printf("<");
	auto iter = list.begin();
	for (int i = 1; i != m; ++i)
		if (++iter == list.end())
			iter = list.begin();
	while (list.size() > 1) {
		printf("%d, ", *iter);
		auto tIter = next(iter, 1);
		list.erase(iter);
		if (tIter == list.end()) tIter = list.begin();
		iter = tIter;
		for (int i = 1; i != m; ++i)
			if (++iter == list.end())
				iter = list.begin();
	}
	printf("%d>", *list.begin());
}
#include<list>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	int N;
	list<pair<int, int>> ls;
	scanf("%d", &N);
	for (int i = 0; i != N; ++i) {
		int x;
		scanf("%d", &x);
		ls.push_back({ i + 1, x });
	}
	auto iter = ls.begin();
	while (true) {
		printf("%d ", iter->first);
		if (ls.size() == 1) break;
		int shift = iter->second;
		auto nextIter = iter;
		if (shift > 0) {
			--shift;
			nextIter = next(iter, 1);
			if (nextIter == ls.end()) nextIter = ls.begin();
			ls.erase(iter);
			shift %= ls.size();
			while (shift != 0) {
				if (++nextIter == ls.end())
					nextIter = ls.begin();
				--shift;
			}
		}
		else {
			++shift;
			if (iter == ls.begin())
				nextIter = prev(ls.end(), 1);
			else
				nextIter = prev(iter, 1);
			ls.erase(iter);
			shift = ls.size() * (int)ceil(-shift / (double)ls.size()) + shift;
			while (shift != 0) {
				if (++nextIter == ls.end())
					nextIter = ls.begin();
				--shift;
			}
		}
		iter = nextIter;
	}
}
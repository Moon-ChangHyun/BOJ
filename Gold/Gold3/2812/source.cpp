// 80ms, 16748KB

#include<cstdio>
#include<list>
using namespace std;

int main() {
	int N, K, L;
	list<int> ls;
	scanf("%d%d", &N, &K);
	L = N - K;
	for (int i = 0; i != N; ++i) {
		int x;
		scanf(" %c", &x);
		ls.push_back(x & 0xf);
	}
	for (auto iter = ls.begin(); ; ) {
		auto next_iter = next(iter, 1);
		if (next_iter == ls.end()) break;
		if (*iter < *next_iter) {
			ls.erase(iter++);
			if (iter != ls.begin()) --iter;
			if (--K == 0)
				break;
		}
		else {
			++iter;
		}
	}
	for (auto iter = ls.begin(); ~--L; ++iter)
		printf("%d", *iter);
}
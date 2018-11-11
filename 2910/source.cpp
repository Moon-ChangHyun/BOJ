#include<cstdio>
#include<map>
#include<vector>
using namespace std;
int main() {
	int N, C;
	scanf("%d%d", &N, &C);
	map<int, int> cnt, firstOf;
	for (int i = 0; i != N; ++i) {
		int x;
		scanf("%d", &x);
		if (cnt[x] == 0)
			firstOf[x] = i;
		++cnt[x];
	}
	vector<map<int, int>> v(1001);
	for (auto iter : cnt)
		v[iter.second].insert({ firstOf[iter.first], iter.first });
	for (int i = 1001; ~--i; )
		for (auto iIter : v[i])
			for (int j = 0; j != i; ++j)
				printf("%d ", iIter.second);
}
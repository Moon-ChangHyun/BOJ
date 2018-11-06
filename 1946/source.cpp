#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int T;
	for (scanf("%d", &T); ~--T;) {
		int n, toCompRankB, candNum = 0;
		scanf("%d", &n);
		toCompRankB = n + 1;
		vector<pair<int, int>> sortedByRankA(n);
		for (auto& iter : sortedByRankA)
			scanf("%d%d", &iter.first, &iter.second);
		sort(sortedByRankA.begin(), sortedByRankA.end());
		for (auto& iter : sortedByRankA) {
			if (toCompRankB > iter.second) {
				toCompRankB = iter.second;
				++candNum;
			}
		}
		printf("%d\n", candNum);
	}
}
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
	int N, ret = 0;
	scanf("%d", &N);
	vector<pair<int, int>> costOrd(N);
	for (int i = 0; i != N; ++i)
		scanf("%d%d", &costOrd[i].second, &costOrd[i].first);
	sort(costOrd.begin(), costOrd.end());
	int mn = 12345;
	for (auto iter : costOrd) {
		if (iter.second < mn) {
			mn = iter.second;
			++ret;
		}
	}
	printf("%d", ret);
}
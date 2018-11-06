#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int l, n;
	scanf("%d", &l);
	vector<int> luckySet(l);
	for (int i = 0; i != l; ++i)
		scanf("%d", &luckySet[i]);
	sort(luckySet.begin(), luckySet.end());
	scanf("%d", &n);
	if (binary_search(luckySet.begin(), luckySet.end(), n)) printf("0");
	else {
		int idx = distance(luckySet.begin(), lower_bound(luckySet.begin(), luckySet.end(), n));
		int lo, hi;
		lo = idx ? luckySet[idx - 1] + 1 : 1;
		hi = luckySet[idx] - 1;
		printf("%d", (n - lo + 1) * (hi - n + 1) - 1);
	}
}
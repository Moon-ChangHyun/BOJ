// 312ms, 12952KB

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> input;
	vector<int> dp;
	vector<int> ind;
	int n;
	scanf("%d", &n);
	input.resize(n);
	ind.resize(n);
	dp.reserve(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &input[i]);
		auto it = lower_bound(dp.begin(), dp.end(), input[i]);
		if (it == dp.end()) {
			dp.push_back(input[i]);
			ind[i] = dp.size() - 1;
		}
		else {
			*it = input[i];
			ind[i] = it - dp.begin();
		}
	}
	int last = dp.size();
	printf("%d\n", last--);
	for (int i = n; --i >= 0;) {
		if (ind[i] == last) {
			dp[last--] = input[i];
		}
	}
	for (auto val : dp)
		printf("%d ", val);
}
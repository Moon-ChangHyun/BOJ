// 4ms, 5844KB

#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
vector<pair<int, int>> v;
int cache[1001][1001];
int n;

int f(int day, int ind) {
	int& ret = cache[day][ind];
	if (ret != -1)
		return ret;
	if (day >= v[ind].first)
		return ret = 0;
	return ret = max(f(day, ind + 1), v[ind].second + f(day + 1, ind + 1));
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i != 1001; ++i) {
		for (int j = 0; j != n; ++j)
			cache[i][j] = -1;
	}
	v.reserve(n);
	for (int i = 0; i != n; ++i) {
		int d, w;
		scanf("%d%d", &d, &w);
		v.push_back({ d, w });
	}
	sort(v.begin(), v.end());
	printf("%d", f(0, 0));
}
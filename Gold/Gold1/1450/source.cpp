// 4ms, 2156KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int N, C, weights[30];
vector<int> leftSideSums;
ll ret;

void funcF(int p, ll sum)
{
	if (sum > C) return;
	if (p < 0) {
		leftSideSums.push_back(sum);
		return;
	}
	funcF(p - 1, sum + weights[p]);
	funcF(p - 1, sum);
}

void funcG(int p, ll sum)
{
	if (sum > C) return;
	if (p >= N)
	{
		auto iter = upper_bound(leftSideSums.begin(), leftSideSums.end(), C - sum);
		ret += (iter - leftSideSums.begin());
		return;
	}
	funcG(p + 1, sum + weights[p]);
	funcG(p + 1, sum);
}

int main()
{
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; ++i)
		scanf("%d", weights + i);
	int p = N / 2;
	leftSideSums.reserve(1 << p);
	funcF(p - 1, 0);
	sort(leftSideSums.begin(), leftSideSums.end());
	funcG(p, 0);
	printf("%lld", ret);
}
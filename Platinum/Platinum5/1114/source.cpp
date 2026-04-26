// 4ms, 1228KB

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int L, K, C, firstCut;
vector<int> pos;

bool func(int maxL)
{
	int cutting = 0, prevCut = L, i = pos.size() - 1;
	if (prevCut - pos[i] > maxL) return false;
	for (;~--i;)
	{
		if (pos[i + 1] - pos[i] > maxL) return false;
		if (prevCut - pos[i] > maxL)
		{
			prevCut = pos[i + 1];
			++cutting;
		}
	}
	firstCut = cutting < C ? pos[1] : prevCut;
	return cutting <= C;
}

int main()
{
	scanf("%d%d%d", &L, &K, &C);
	pos.resize(K + 1);
	pos[0] = 0;
	for (int i = 1; i <= K; ++i)
		scanf("%d", &pos[i]);
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	int lo = 0, hi = L;
	while (lo + 1 != hi)
	{
		int mid = (lo + hi) >> 1;
		if (func(mid))
			hi = mid;
		else
			lo = mid;
	}
	func(hi);
	printf("%d %d", hi, firstCut);
}
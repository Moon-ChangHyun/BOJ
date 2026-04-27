// 0ms, 1232KB

#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;

int n, m, p[10], k = 51;
int bestLen, bestNumbers[10];
int curLen, curNumbers[10];
int maxLen[51][10];

void func(int remain, int upper)
{
	if (remain < 0 || upper < 0) return;
	if (curLen > 0 && maxLen[remain][upper] >= curLen) return;
	maxLen[remain][upper] = curLen;
	if (curLen > bestLen && curLen > curNumbers[0])
	{
		copy(curNumbers, curNumbers + n, bestNumbers);
		bestLen = curLen;
	}
	++curLen;
	++curNumbers[upper];
	func(remain - p[upper], upper);
	--curLen;
	--curNumbers[upper];
	func(remain, upper - 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", p + i);
		k = min(k, p[i]);
	}
	scanf("%d", &m);
	func(m, n - 1);
	if (bestNumbers[0] == bestLen)
		putchar('0');
	else
	{
		string ret;
		ret.reserve(bestLen);
		for (int i = n; ~--i;)
		{
			while (bestNumbers[i])
			{
				ret.push_back(i + '0');
				--bestNumbers[i];
			}
		}
		printf("%s", ret.c_str());
	}
}
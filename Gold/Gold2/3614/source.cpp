// 80ms, 1240KB

#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> gList;
	int sqrtN = sqrt(N);
	for (int g = 1; g <= sqrtN; ++g)
	{
		if (N % g) continue;
		gList.push_back(g);
	}
	gList.reserve(gList.size() * 2);
	int i = gList.size();
	if (gList.back() * gList.back() == N)
		--i;
	for (; ~--i;)
		gList.push_back(N / gList[i]);
	
	int ret = 0;
	for (auto g : gList)
	{
		int x = (N / g) + 1;
		int hx = x >> 1;
		for (int i = 1; i <= hx; ++i)
		{
			if (gcd(x - i, i) > 1) continue;
			++ret;
		}
	}
	printf("%d", ret);
}
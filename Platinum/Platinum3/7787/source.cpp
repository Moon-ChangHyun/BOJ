// 0ms, 1112KB

#include<cstdio>
#include<cmath>

int getNim(long long num)
{
	if (num & 1) return 1;
	else if (num == 0) return 0;
	int i = 1;
	long long x = 2;
	while (x < num)
	{
		++i;
		x <<= 1;
	}
	if (num == x)
		return i + 1;
	else
		return getNim(num - (x >> 1));
}

int main()
{
	int r, g;
	scanf("%d%d", &r, &g);
	printf("%c player wins", (getNim(r) ^ getNim(g)) == 0 ? 'B' : 'A');
}
// 0ms, 1112KB

#include<cstdio>

int main()
{
	int N;
	scanf("%d", &N);

	unsigned totalGrundy = 0;
	for (int i = 0; i < N; ++i)
	{
		unsigned x;
		scanf("%u", &x);
		unsigned grundy;
		if (x & 1)
			grundy = (x + 1) >> 1;
		else if (x <= 2)
			grundy = 0;
		else
			grundy = (x - 2) >> 1;
		totalGrundy ^= grundy;
	}
	printf("%s", totalGrundy ? "koosaga" : "cubelover");
}
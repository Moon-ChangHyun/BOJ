// 0ms, 1112KB

#include<cstdio>
int main()
{
	int N, G = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int x;
		scanf("%d", &x);
		if (x > 0)
		{
			int tmp = x % 4;
			if (tmp == 0)
				--x;
			else if (tmp == 3)
				++x;
		}
		G ^= x;
	}
	printf("%s", G ? "koosaga" : "cubelover");
}
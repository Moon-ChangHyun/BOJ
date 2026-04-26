// 0ms, 1116KB

#include<cstdio>

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	long long a1 = x2 - x1, a2 = y2 - y1;
	long long b1 = x3 - x1, b2 = y3 - y1;
	long long val = a1 * b2 - a2 * b1;
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

int func()
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	int ccw123 = ccw(x1, y1, x2, y2, x3, y3);
	int ccw124 = ccw(x1, y1, x2, y2, x4, y4);
	if (ccw123 == 0)
	{
		if (ccw124 == 0)
		{
			if (x1 < x2)
			{
				if (x3 < x4)
					return x3 <= x2 && x1 <= x4;
				return x4 <= x2 && x1 <= x3;
			}
			else if (x1 > x2)
			{
				if (x3 < x4)
					return x3 <= x1 && x2 <= x4;
				return x4 <= x1 && x2 <= x3;
			}
			else
			{
				if (y1 < y2)
				{
					if (y3 < y4)
						return y3 <= y2 && y1 <= y4;
					return y4 <= y2 && y1 <= y3;
				}
				else
				{
					if (y3 < y4)
						return y3 <= y1 && y2 <= y4;
					return y4 <= y1 && y2 <= y3;
				}				
			}
		}
		if (x1 < x2)
			return x1 <= x3 && x3 <= x2;
		else if (x1 > x2)
			return x2 <= x3 && x3 <= x1;
		else
		{
			if (y1 < y2)
				return y1 <= y3 && y3 <= y2;
			else
				return y2 <= y3 && y3 <= y1;
		}
	}
	else
	{
		if (ccw124 == 0)
		{
			if (x1 < x2)
				return x1 <= x4 && x4 <= x2;
			else if (x1 > x2)
				return x2 <= x4 && x4 <= x1;
			else
			{
				if (y1 < y2)
					return y1 <= y4 && y4 <= y2;
				else
					return y2 <= y4 && y4 <= y1;
			}
		}
		else
		{
			if (ccw123 * ccw124 == 1) return 0;
			int ccw341 = ccw(x3, y3, x4, y4, x1, y1);
			int ccw342 = ccw(x3, y3, x4, y4, x2, y2);
			return ccw341 * ccw342 <= 0;
		}
	}
}

int main() {
	printf("%d", func());
}
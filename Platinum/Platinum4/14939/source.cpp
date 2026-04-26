// 0ms, 1176KB

#include<cstdio>
#include<vector>

using namespace std;

int n = 10, nSqr = 100, answer = 101;
vector<vector<bool>> input(10, vector<bool>(10));

const int dy[5] = { 0, -1, 0, 1, 0 };
const int dx[5] = { 0, 0, 1, 0, -1 };

void toggle(int y, int x)
{
	for (int k = 0; k < 5; ++k)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (0 <= ny && ny < n && 0 <= nx && nx < n)
			input[ny][nx] = !input[ny][nx];
	}
}

void func(int idx, int sum)
{
	if (sum > answer) return; //가지치기
	if (idx == nSqr)
	{
		if (!input[n - 1][n - 1])
			answer = sum;
		return;
	}

	int y = idx / n, x = idx % n;
	if (y == 0) //첫 줄은 완전 탐색
	{
		toggle(y, x);
		func(idx + 1, sum + 1);
		toggle(y, x);
		func(idx + 1, sum);
	}
	else
	{
		if (y == n - 1 && x && input[y - 1][x] != input[y][x - 1]) //마지막 줄이면서 윗칸과 왼칸이 다르면 실패
			return;

		if (input[y - 1][x])
		{
			toggle(y, x);
			func(idx + 1, sum + 1);
			toggle(y, x);
		}
		else
			func(idx + 1, sum);
	}
}

int main()
{
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		{
			char c;
			scanf(" %c", &c);
			if (c == 'O')
				input[i][j] = true;
		}

	func(0, 0);
	if (answer == 101)
		printf("-1");
	else
		printf("%d", answer);
}
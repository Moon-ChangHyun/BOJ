// 104ms, 2340KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
constexpr int INF = 1987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	for (cin >> T; ~--T; )
	{
		int N, W, ans;
		cin >> N >> W;

		vector<vector<int>> input(2, vector<int>(N + 1));
		vector<int> dpA(N + 1), dpB(N + 1), dpC(N + 1);

		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < N; ++j)
				cin >> input[i][j];
		input[0][N] = input[0][0];
		input[1][N] = input[1][0];

		if (N == 1)
		{
			cout << (input[0][0] + input[1][0] <= W ? 1 : 2) << '\n';
			continue;
		}

		//둘 다 0~n-1
		dpA[N] = 0;
		dpB[N] = INF;
		dpC[N] = INF;
		for (int i = N; ~--i; )
		{
			bool cond1 = input[1][i] + input[1][i + 1] <= W;
			bool cond2 = input[0][i] + input[0][i + 1] <= W;
			dpB[i] = 1 + dpA[i + 1];
			if (cond1)
				dpB[i] = min(dpB[i], dpC[i + 1]);
			dpC[i] = 1 + dpA[i + 1];
			if (cond2)
				dpC[i] = min(dpC[i], dpB[i + 1]);
			dpA[i] = 1 + min(dpB[i], dpC[i]);
			if (input[0][i] + input[1][i] <= W)
				dpA[i] = min(dpA[i], dpA[i + 1]);
			if (cond1 && cond2)
				dpA[i] = min(dpA[i], i < N - 1 ? dpA[i + 2] : 0);
		}
		ans = dpA[0];

		//둘 다 1~n
		dpA[N] = input[0][N] + input[1][N] <= W ? 0 : 2;
		dpB[N] = 1;
		dpC[N] = 1;
		for (int i = N; --i; )
		{
			bool cond1 = input[1][i] + input[1][i + 1] <= W;
			bool cond2 = input[0][i] + input[0][i + 1] <= W;
			dpB[i] = 1 + dpA[i + 1];
			if (cond1)
				dpB[i] = min(dpB[i], dpC[i + 1]);
			dpC[i] = 1 + dpA[i + 1];
			if (cond2)
				dpC[i] = min(dpC[i], dpB[i + 1]);
			dpA[i] = 1 + min(dpB[i], dpC[i]);
			if (input[0][i] + input[1][i] <= W)
				dpA[i] = min(dpA[i], dpA[i + 1]);
			if (cond1 && cond2)
				dpA[i] = min(dpA[i], i < N - 1 ? dpA[i + 2] : 0);
		}
		ans = min(ans, dpA[1]);

		//0행: 1~n, 1행: 0~n-1
		dpA[N] = INF;
		dpB[N] = 0;
		dpC[N] = 1;
		dpB[N - 1] = 2;
		dpC[N - 1] = input[0][N - 1] + input[0][N] <= W ? 0 : 2;
		dpA[N - 1] = input[0][N - 1] + input[1][N - 1] <= W ? 1 : 1 + dpC[N - 1];
		for (int i = N - 1; ~--i; )
		{
			bool cond1 = input[1][i] + input[1][i + 1] <= W;
			bool cond2 = input[0][i] + input[0][i + 1] <= W;
			dpB[i] = 1 + dpA[i + 1];
			if (cond1)
				dpB[i] = min(dpB[i], dpC[i + 1]);
			dpC[i] = 1 + dpA[i + 1];
			if (cond2)
				dpC[i] = min(dpC[i], dpB[i + 1]);
			dpA[i] = 1 + min(dpB[i], dpC[i]);
			if (input[0][i] + input[1][i] <= W)
				dpA[i] = min(dpA[i], dpA[i + 1]);
			if (cond1 && cond2)
				dpA[i] = min(dpA[i], dpA[i + 2]);
		}
		ans = min(ans, dpB[0]);

		//0행: 0~n-1, 1행: 1~n
		dpA[N] = INF;
		dpB[N] = 1;
		dpC[N] = 0;
		dpB[N - 1] = input[1][N - 1] + input[1][N] <= W ? 0 : 2;
		dpC[N - 1] = 2;
		dpA[N - 1] = input[0][N - 1] + input[1][N - 1] <= W ? 1 : 1 + dpB[N - 1];
		for (int i = N - 1; ~--i; )
		{
			bool cond1 = input[1][i] + input[1][i + 1] <= W;
			bool cond2 = input[0][i] + input[0][i + 1] <= W;
			dpB[i] = 1 + dpA[i + 1];
			if (cond1)
				dpB[i] = min(dpB[i], dpC[i + 1]);
			dpC[i] = 1 + dpA[i + 1];
			if (cond2)
				dpC[i] = min(dpC[i], dpB[i + 1]);
			dpA[i] = 1 + min(dpB[i], dpC[i]);
			if (input[0][i] + input[1][i] <= W)
				dpA[i] = min(dpA[i], dpA[i + 1]);
			if (cond1 && cond2)
				dpA[i] = min(dpA[i], dpA[i + 2]);
		}
		ans = min(ans, dpC[0]);

		cout << (((N << 1) - ans) >> 1) + ans << '\n';
	}
}
// 32ms, 1232KB

#include<cstdio>
#include<vector>

using namespace std;
using ll = long long;

constexpr int MOD = 1000003;

int L;
vector<vector<int>> E;

vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B)
{
	vector<vector<int>> ret(L, vector<int>(L));
	for (int i = 0; i < L; ++i)
		for (int j = 0; j < L; ++j)
			for (int k = 0; k < L; ++k)
				ret[i][j] = (ret[i][j] + ((ll)A[i][k] * B[k][j]) % MOD) % MOD;
	return ret;
}

vector<vector<int>> power(const vector<vector<int>>& A, int t)
{
	if (t == 0)
		return E;
	if (t & 1)
		return multiply(A, power(A, t - 1));
	else
	{
		auto half = power(A, t >> 1);
		return multiply(half, half);
	}
}

int main()
{
	int N, s, e, T;
	scanf("%d%d%d%d", &N, &s, &e, &T);
	--s; --e;
	L = 5 * N;
	vector<vector<int>> adj(L, vector<int>(L));
	for (int i = 0; i < N; ++i)
	{
		int src = i * 5;
		for (int j = 0; j < N; ++j)
		{
			int val;
			scanf("%1d", &val);
			if (val)
				adj[src][j * 5 + val - 1] = 1;
		}
		for (int k = 0; k < 4; ++k)
			adj[src + k + 1][src + k] = 1;
	}
	E.resize(L, vector<int>(L));
	for (int i = 0; i < L; ++i)
			E[i][i] = 1;
	printf("%d", power(adj, T)[s * 5][e * 5]);
}
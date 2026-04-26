// 76ms, 14250KB

#include<iostream>
#include<vector>

using namespace std;

int N, K, M, sparse[100001][31];

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> K >> M;
	vector<int> student(N);
	for (int i = 0; i < N; ++i)
		cin >> student[i];
	for (int i = 1; i <= K; ++i)
		cin >> sparse[i][0];
	for (int j = 1; j < 31; ++j)
		for (int i = 1; i <= K; ++i)
			sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
	
	for (auto st : student)
	{
		int a = st;
		int b = M - 1;
		int x = 30, y = 1 << 30;
		
		while (b)
		{
			while (b < y)
			{
				--x;
				y >>= 1;
			}
			a = sparse[a][x];
			b -= y;
		}
		cout << a << ' ';
	}
}
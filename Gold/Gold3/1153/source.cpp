// 8ms, 2148KB

#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

vector<bool> isPrime;
vector<int> primeNum;

pair<int, int> func(int num) //num > 2인 짝수
{
	for (int i = 0; i < primeNum.size(); ++i)
	{
		//if (num <= primeNum[i]) break;
		if (isPrime[num - primeNum[i]])
			return { primeNum[i], num - primeNum[i] };
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	if (N < 8)
	{
		printf("-1");
		return 0;
	}
	isPrime.resize(N + 1, true);
	isPrime[0] = isPrime[1] = false;
	int sqrtN = sqrt(N);
	for (int i = 2; i <= sqrtN; ++i)
	{
		if (!isPrime[i]) continue;
		primeNum.push_back(i);
		for (int j = i * i; j <= N; j += i)
			isPrime[j] = false;
	}
	for (int i = sqrtN + 1; i <= N; ++i)
		if (isPrime[i])
			primeNum.push_back(i);
	
	for (int a = 4; a <= N - 4; a += 2)
	{
		int b = N - a;

		if (b & 1)
		{
			if (isPrime[b - 2])
			{
				auto aPair = func(a);
				printf("%d %d %d %d", aPair.first, aPair.second, 2, b - 2);
				break;
			}
		}
		else
		{
			auto aPair = func(a);
			auto bPair = func(b);
			printf("%d %d %d %d", aPair.first, aPair.second, bPair.first, bPair.second);
			break;
		}
	}
}
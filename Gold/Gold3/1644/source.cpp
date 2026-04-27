// 36ms, 4816KB

#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
    if (N == 1)
    {
        putchar('0');
        return 0;
    }
	vector<bool> isPrime(N + 1, true);
	vector<int> primes;
	isPrime[0] = isPrime[1] = false;
    int sqrtN = sqrt(N);
	for (int i = 2; i <= sqrtN; ++i)
	{
		if (!isPrime[i]) continue;
		primes.push_back(i);
		for (int j = i * i; j <= N; j += i)
			isPrime[j] = false;
	}
    for (int i = sqrtN + 1; i <= N; ++i)
        if (isPrime[i])
            primes.push_back(i);
	int e = primes.size(), l = 0, r = 0, s = primes[0];
	int ret = s == N;
	while (l <= r)
	{
		if (s <= N)
		{
			if (r == e - 1) break;
			s += primes[++r];
		}
		else
			s -= primes[l++];
		if (s == N) ++ret;
	}
	printf("%d", ret);
}
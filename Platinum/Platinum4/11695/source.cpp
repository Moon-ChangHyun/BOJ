// 0ms, 1112KB

#include<cstdio>
int main()
{
    int N, M;
    long long G = 0;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
    {
        long long sum = 0;
        for (int j = 0; j < M; ++j)
        {
            int x;
            scanf("%d", &x);
            sum += x;
        }
        G ^= sum;
    }
    printf("%s", G ? "august14" : "ainta");
}
// 0ms, 1112KB

#include<cstdio>
int main()
{
    int N, x, ns = 0;
    for(scanf("%d", &N); ~--N; )
    {
        scanf("%d", &x);
        ns ^= x;
    }
    printf("%s", ns ? "koosaga" : "cubelover");
}
// 0ms, 1116KB

#include<cstdio>
int rock[1000];
int main()
{
    int n, x = 0, ret = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", rock + i);
        x ^= rock[i];
    }
    if (x == 0)
        putchar('0');
    else
    {
        for (int i = 0; i < n; ++i)
            if ((x ^ rock[i]) <= rock[i])
                ++ret;
        printf("%d", ret);
    }
}
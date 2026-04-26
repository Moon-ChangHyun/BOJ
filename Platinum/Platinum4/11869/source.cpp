// 0ms, 1112KB

#include<cstdio>
int main()
{
    int M, G = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        int p;
        scanf("%d", &p);
        G ^= p;
    }
    printf("%s", G ? "koosaga" : "cubelover");
}
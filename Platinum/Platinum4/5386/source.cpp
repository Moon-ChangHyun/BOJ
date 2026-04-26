// 0ms, 1112KB

#include<cstdio>

int main()
{
	int T;
    for (scanf("%d", &T);~--T;)
    {
        int S, K, X;
        scanf("%d%d", &S, &K);
        if (K & 1)
        {
            X = S & 1;
        }
        else
        {
            X = S % (K + 1);
            if (X == K) X = K;
            else if(X & 1) X = 1;
            else X = 0;
        }
        printf("%d\n", X);
    }
}
// 552ms, 4008KB

#include<iostream>
using namespace std;
int start;
int N,M;
bool like[1005][1005];
int bMatch[1005];
bool visited[1010][1010];
   
bool dfs(bool* v, int a)
{
    if(v[a]) return false;
    v[a]=true;
       
    for(int b=0;b<M;++b)
    {
        if(like[a][b])
        {
            if(bMatch[b]==-1 || dfs(v, bMatch[b]))
            {
                bMatch[b]=a;
                return true;
            }
        }
    }
    return false;
}
int maximum_flow()
{
    int size=0,i;
    for(int i=0; i!=M; ++i) bMatch[i]=-1;
    for(start=0;start<N;++start)
    {
        if(dfs(visited[start], start)) ++size;
    }
       
    return size;
       
}
int main( )
{
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;++i)
    {
        int k,x;
        scanf("%d",&k);
        for(int j=0;j<k;++j)
        {
            scanf("%d",&x);
            like[i-1][x-1]=1;
        }
    }
    printf("%d\n",maximum_flow());
    return 0;
}

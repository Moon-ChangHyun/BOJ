// 512ms, 1228KB

#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
int N, M;
vector<pair<int,int>> adj;
vector<int> bMatch;
bitset<1001> aVisit;
bool dfs(int a) {
    if(aVisit[a]) return false;
    aVisit[a] = true;
    for(int i = adj[a].first; i <= adj[a].second; ++i) {
        if(bMatch[i] == 0 || dfs(bMatch[i])) {
            bMatch[i] = a;
            return true;
        }
    }
    return false;
}
int main() {
    int T;
    for(scanf("%d", &T); ~--T;) {
        scanf("%d%d", &N, &M);
        adj.clear();
        adj.resize(M + 1);
        bMatch.clear();
        bMatch.resize(N + 1);
        for(int i = 1; i <= M; ++i)
            scanf("%d%d", &adj[i].first, &adj[i].second);
        int ret = 0;
        for(int i = 1; i <= M; ++i){
            aVisit.reset();
            if(dfs(i)) ++ret;
        }
        printf("%d\n", ret);
    }
}
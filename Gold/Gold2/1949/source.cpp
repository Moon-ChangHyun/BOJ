// 0ms, 3336KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> pop;
vector<vector<int>> adj;
vector<int> dp[2];

int func(int nd, int parent, char pSel)
{
    int& ret = dp[pSel][nd];
    if (ret != -1) return ret;
    ret = 0;
    
    if (pSel)
    {
        for (auto child : adj[nd])
        {
            if (child == parent) continue;
            ret += func(child, nd, 0);
        }
    }
    else
    {
        int a = pop[nd], b = 0;
        for (auto child : adj[nd])
        {
            if (child == parent) continue;
            a += func(child, nd, 1);
            b += func(child, nd, 0);
        }
        ret = max(a, b);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    pop.resize(N + 1);
    adj.resize(N + 1);
    for (int i = 0; i < 2; ++i)
        dp[i].resize(N + 1, -1);
    for (int i = 1; i <= N; ++i)
        cin >> pop[i];
    for (int i = 1; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << func(1, 0, 0);
}
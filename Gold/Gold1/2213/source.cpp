// 4ms, 2820KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> weights;
vector<vector<int>> adj;
vector<int> dp[2];
vector<bool> sel;
vector<int> ans;

int dfs(int nd, int parent, char parentSelected)
{
    int& ret = dp[parentSelected][nd];
    if (ret != -1) return ret;
    ret = 0;
    for (auto next : adj[nd])
    {
        if (next == parent) continue;
        ret += dfs(next, nd, 0);
    }
    if (!parentSelected)
    {
        int sumWhenSel = 0;
        for (auto next : adj[nd])
        {
            if (next == parent) continue;
            sumWhenSel += dfs(next, nd, 1);
        }
        sumWhenSel += weights[nd];
        if (sumWhenSel > ret)
        {
            ret = sumWhenSel;
            sel[nd] = true;
        }
    }
    return ret;
}

void reconstruct(int nd, int parent, char parentSelected)
{
    bool get = !parentSelected && sel[nd];
    if (get)
        ans.push_back(nd);
    for (auto next : adj[nd])
    {
        if (next == parent) continue;
        reconstruct(next, nd, get);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    weights.resize(N + 1);
    adj.resize(N + 1);
    sel.resize(N + 1);
    dp[0].resize(N + 1, -1);
    dp[1].resize(N + 1, -1);
    for (int i = 1; i <= N; ++i)
        cin >> weights[i];
    for (int i = 1; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(1, 0, 0) << '\n';
    reconstruct(1, 0, 0);
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << ' ';
}
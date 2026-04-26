// 0ms, 2020KB

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> dist(N, vector<int>(N));
    vector<vector<int>> adj(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> dist[i][j];
            adj[i][j] = dist[i][j];
        }
    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            if (i == k) continue;
            for (int j = i + 1; j < N; ++j)
            {
                if (j == k) continue;
                if (dist[i][k] + dist[k][j] == dist[i][j])
                    adj[i][j] = adj[j][i] = 0;
                else if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            ret += adj[i][j];
    cout << ret;
}
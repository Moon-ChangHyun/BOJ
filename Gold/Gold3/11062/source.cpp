// 84ms, 9836KB

#include<iostream>
#include<algorithm>

using namespace std;

int N, card[1000];
pair<int, bool> dp[1000][1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; ~--T; )
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> card[i];
            dp[i][i] = { card[i], true };
        }
        if (N > 1)
            for (int i = 1; i < N; ++i)
                dp[i - 1][i] = card[i - 1] <= card[i] ? make_pair( card[i], true ) : make_pair(card[i - 1], false);
        for (int l = 2; l <= N; ++l)
        {
            for (int a = N - l; ~--a; )
            {
                int b = a + l;
                int x1 = card[a] + (dp[a + 1][b].second ? dp[a + 1][b - 1].first : dp[a + 2][b].first);
                int x2 = card[b] + (dp[a][b - 1].second ? dp[a][b - 2].first : dp[a + 1][b - 1].first);
                dp[a][b] = x1 <= x2 ? make_pair(x2, true) : make_pair(x1, false);
            }
        }
        cout << dp[0][N - 1].first << '\n';
    }
}
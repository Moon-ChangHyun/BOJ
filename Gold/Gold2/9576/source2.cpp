// 8ms, 1984KB

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
struct BNum
{
    int s, e;
};

bool compare(BNum a, BNum b)
{
    if (a.e == b.e)
        return a.s < b.s;
    return a.e < b.e;
}
int main()
{
    int T, n, m;
    cin >> T;
    bool visit[1001];
    while (T--)
    {
        cin >> n >> m;
        BNum book[1001];
        
        int s, e;
        for (int i = 0; i < m; i++)
        {
            cin >> book[i].s >> book[i].e;
        }

        sort(book, book + m, compare);

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = book[i].s; j < n + 1; j++)
            {
                if (j <= book[i].e && !visit[j])
                {
                    ans++;
                    visit[j] = true;
                    break;
                }
            }
        }
        cout << ans << '\n';
        memset(visit, 0, sizeof(visit));
    }

    return 0;
}
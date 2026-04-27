// 140ms, 9836KB

#include <iostream>

using namespace std;
using ll = long long;

ll pSum[1000001];
int rem[1000] = {1};

int main()
{
    ios::sync_with_stdio(false);
    int N, M;
    ll ret = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> pSum[i];
        pSum[i] += pSum[i - 1];
        int r = pSum[i] % M;
        ret += rem[r]++;
    }
    cout << ret;
}
// 0ms, 2212KB

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, K, R1, R2, C1, C2;
vector<vector<char>> board;

void func(int y, int x, int length)
{
    if (length == 1 || y > R2 || x > C2 || y + length <= R1 || x + length <= C1) return;
    int nextLength = length / N;
    int tmp = (N - K) / 2;
    int midS = nextLength * tmp, midL = nextLength * K;

    int rA = max(y + midS, R1);
    int rB = min(y + midS + midL - 1, R2);
    int cA = max(x + midS, C1);
    int cB = min(x + midS + midL - 1, C2);
    for (int i = rA; i <= rB; ++i)
        for (int j = cA; j <= cB; ++j)
            board[i - R1][j - C1] = '1';

    for (int i = 0; i < tmp; ++i)
        for (int j = 0; j < N; ++j)
            func(y + nextLength * i, x + nextLength * j, nextLength);
    for (int i = N - tmp; i < N; ++i)
        for (int j = 0; j < N; ++j)
            func(y + nextLength * i, x + nextLength * j, nextLength);
    for (int i = tmp; i < N - tmp; ++i)
    {
        for (int j = 0; j < tmp; ++j)
            func(y + nextLength * i, x + nextLength * j, nextLength);
        for (int j = N - tmp; j < N; ++j)
            func(y + nextLength * i, x + nextLength * j, nextLength);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int s;
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
    board.resize(R2 - R1 + 1, vector<char>(C2 - C1 + 1, '0'));
    func(0, 0, pow(N, s));
    for (const auto& row : board)
    {
        for (const auto c : row)
            cout << c;
        cout << '\n';
    }
}
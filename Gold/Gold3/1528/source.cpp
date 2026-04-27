// 160ms, 11308KB

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
constexpr int inf = 987654321;

int N;
vector<int> delta;
vector<int> dp; //inf:미정, -1:답없음
vector<int> parent;

void calcDelta(int val) {
    if (val > N)
        return;
    delta.push_back(val);
    int next = val * 10 + 4;
    calcDelta(next);
    next = val * 10 + 7;
    calcDelta(next);
}

bool func(int val) {
    queue<int> q;
    q.push(0);
    dp[0] = 0;
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        if (x == val)
            break;
        for (auto d : delta) {
            int next = x + d;
            if (next <= val && dp[next] == inf) {
                q.push(next);
                dp[next] = dp[x] + 1;
                parent[next] = x;
            }
        }
    }
    return dp[val] != inf;
}

void reconstruct(int val, vector<int>& out) {
    if (val == 0)
        return;
    out.push_back(val - parent[val]);
    reconstruct(parent[val], out);
}

int main() {
    cin >> N;
    if (N <= 0) {
        cout << -1;
        return 0;
    }

    dp.resize(N + 1, inf);
    parent.resize(N + 1, -1);
    dp[0] = 0;
    calcDelta(4);
    calcDelta(7);
    sort(delta.begin(), delta.end(), [](int a, int b) {
        auto aStr = to_string(a);
        auto bStr = to_string(b);
        if (aStr.size() < bStr.size())
            return true;
        if (aStr.size() > bStr.size())
            return false;
        return aStr < bStr;
    });

    if (!func(N)) {
        cout << -1;
        return 0;
    }
    vector<int> ans;
    reconstruct(N, ans);

    for (auto rIter = ans.rbegin(); rIter != ans.rend(); ++rIter)
        cout << *rIter << ' ';
}
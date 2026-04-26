// 100ms, 41092KB

//  dp[i] = (0, i] 범위에서의 최적해 = max(0 ≤ j < i) {dp[j] + a(psum[i] - psum[j])^2 + b(psum[i] - psum[j]) + c}
//  dp[i] = max(0 ≤ j < i) { A(i)B(j) + C(j) } +D(i)
//  A(i) = psum[i]//단조증가
//  B(j) = -2 * a * psum[j] //단조증가(a < 0 이므로)
//  C(j) = a * psum[j] ^ 2 - b * psum[j] + dp[j]
//  D(i) = a * psum[i] ^ 2 + b * psum[i] + c
#include<iostream>
#include<vector>
using namespace std;

struct positiveHalfLine {
    long long a, b;
    double startX;
};
double xOfCross(positiveHalfLine& f1, positiveHalfLine& f2) {
    return (f2.b - f1.b) / double(f1.a - f2.a);
}

int main() {
    ios::sync_with_stdio(false);
    int n, a, b, c, prevSelected = 0;
    cin >> n >> a >> b >> c;
    vector<long long> psum(n + 1);
    vector<long long> dp(n + 1);
    vector<positiveHalfLine> hfLines;
    hfLines.reserve(n);
    psum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        positiveHalfLine newLine{ -2 * a * psum[i - 1], a * psum[i - 1] * psum[i - 1] - b * psum[i - 1] + dp[i - 1], 0.0 };
        while (!hfLines.empty()) {
            newLine.startX = xOfCross(hfLines.back(), newLine);
            if (hfLines.back().startX < newLine.startX) break;
            hfLines.pop_back();
            if (hfLines.size() == prevSelected) --prevSelected;
        }
        hfLines.push_back(newLine);
        while (prevSelected + 1 < hfLines.size() && hfLines[prevSelected + 1].startX < psum[i]) ++prevSelected;
        auto& sel = hfLines[prevSelected];
        dp[i] = sel.a * psum[i] + sel.b + a * psum[i] * psum[i] + b * psum[i] + c;
    }
    cout << dp[n];
}
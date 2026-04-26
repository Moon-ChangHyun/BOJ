// 32ms, 5996KB

#include<iostream>
#include<vector>
using namespace std;
struct positiveHalfLine {
	double startX;
	int a;
	long long b;
};
double xOfCross(positiveHalfLine& f1, positiveHalfLine& f2) {
	return (f2.b - f1.b) / double(f1.a - f2.a);
}
int main() {
	ios::sync_with_stdio(false);
	int n, prevSelected = 0;
	cin >> n;
	vector<int> a(n), b(n);
	vector<long long> dp(n);
	vector<positiveHalfLine> hfLines;
	hfLines.reserve(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	dp[0] = 0;
	for (int i = 1; i < n; ++i) {
		positiveHalfLine newLine{ 0.0, b[i - 1],dp[i - 1] };
		while (!hfLines.empty()) {
			newLine.startX = xOfCross(hfLines.back(), newLine);
			if (hfLines.back().startX < newLine.startX) break;
			hfLines.pop_back();
			if (hfLines.size() == prevSelected) --prevSelected;
		}
		hfLines.push_back(newLine);
		while (prevSelected + 1 < hfLines.size() && hfLines[prevSelected + 1].startX < a[i]) ++prevSelected;
		auto& sel = hfLines[prevSelected];
		dp[i] = (long long)sel.a * a[i] + sel.b;
	}
	cout << dp[n - 1];
}
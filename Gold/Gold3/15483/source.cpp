// 4ms, 5908KB

#include<iostream>
#include<algorithm>
using namespace std;
string aString, bString;
int dp[1002][1002];
int main() {
	cin >> aString >> bString;
	for (int i = 0; i <= aString.length(); ++i)
		dp[i][0] = i;
	for (int j = 0; j <= bString.length(); ++j)
		dp[0][j] = j;
	for (int i = 1; i <= aString.length(); ++i) {
		for (int j = 1; j <= bString.length(); ++j) {
			if (aString[i - 1] == bString[j - 1])
				dp[i][j] = min({ dp[i - 1][j - 1], 1 + dp[i - 1][j], 1 + dp[i][j - 1] });
			else
				dp[i][j] = 1 + min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] });
		}
	}
	cout << dp[aString.length()][bString.length()];
}
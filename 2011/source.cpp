#include<iostream>
#include<string>
#define MOD 1000000
using namespace std;
int dp[5000];
string str;
int func(int idx) {//idx번부터 나올 수 해석의 수
	if (idx == str.size()) return 1;
	if (idx == str.size() - 1) return (str[idx] != '0');
	int& ret = dp[idx];
	if (ret != -1)
		return ret;
	if (str[idx] == '0')
		return 0;
	if (str[idx] == '1')
		return ret = (func(idx + 1) + func(idx + 2)) % MOD;
	if (str[idx] == '2') {
		if (str[idx + 1] <= '6')
			return ret = (func(idx + 1) + func(idx + 2)) % MOD;
		else
			return ret = func(idx + 1);
	}
	return ret = func(idx + 1);
}

int main() {
	cin >> str;
	for (int i = 0; i != str.size(); ++i)
		dp[i] = -1;
	cout << func(0);
}
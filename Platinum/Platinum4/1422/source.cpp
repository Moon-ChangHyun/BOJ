// 0ms, 1992KB

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int K, N, mx = 0;
	string mxString;
	cin >> K >> N;
	vector<string> v(K);
	for (auto& val : v) {
		int x;
		cin >> x;
		mx = max(mx, x);
		val = to_string(x);
	}
	mxString = to_string(mx);
	sort(v.begin(), v.end(), [](const string& s1, const string& s2) {
		return stoull(s1 + s2) > stoull(s2 + s1);
	});
	for (auto& val : v) {
		cout << val;
		if (val == mxString) {
			for (int f = N - K; ~--f;)
				cout << val;
			mxString.clear();
		}
	}
}
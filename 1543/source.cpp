#include<string>
#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str, niddle;
	getline(cin, str);
	getline(cin, niddle);
	int start = 0, cnt = 0;
	while (true) {
		int idx = str.find(niddle, start);
		if (idx == string::npos) break;
		++cnt;
		start = idx + niddle.size();
	}
	cout << cnt;
}
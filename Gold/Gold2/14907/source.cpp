// 0ms, 1992KB

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int> adj[26];
int dp[26], delay[26];

int func(int node) {
	int& ret = dp[node];
	if(ret) return ret;
	for(auto iter : adj[node])
		ret = max(ret, func(iter));
	return (ret += delay[node]);
}

int main() {
	ios::sync_with_stdio(false);
	while(true) {
		char node;
		cin >> node;
		if(cin.eof()) break;
		cin >> delay[node - 'A'];
		if(cin.get() == ' ') {
			string s;
			cin >> s;
			for(auto iter : s)
				adj[node - 'A'].push_back(iter - 'A');
		}
	}
	for(int i = 0; i != 26; ++i)
		if(adj[i].empty())
			dp[i] = delay[i];
	int ret = 0;
	for(int i = 0; i != 26; ++i)
		ret = max(ret, func(i));
	cout << ret;
}
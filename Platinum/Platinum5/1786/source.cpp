// 128ms, 16444KB

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string T, P;
	getline(cin, T);
	getline(cin, P);
	vector<size_t> pi(P.size(), 0), ans;
	for (int i = 1, j = 0; i < P.size(); ++i) {
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j])
			pi[i] = ++j;
	}
	for (int i = 0, j = 0; i < T.size(); ++i) {
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				ans.push_back(i + 1 - P.size());
				j = pi[j];
			}
			else
				++j;
		}
	}
	cout << ans.size() << endl;
	for (auto idx : ans)
		cout << idx + 1 << ' ';
}
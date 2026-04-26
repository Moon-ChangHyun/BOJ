// 136ms, 10656KB

#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> lastParty(N + 1, 0);
	vector<int> minDangerParty(N + 1, M + 1);
	vector<vector<int>> party(M + 1);
	for (int i = 1; i <= M; ++i) {
		int x;
		cin >> x;
		party[i].reserve(x);
		for (int j = 1; j <= x; ++j) {
			int k;
			cin >> k;
			lastParty[k] = i;
			party[i].push_back(k);
		}
	}
	for (int i = 1; i <= N; ++i) {
		int x;
		cin >> x;
		if (x) {
			minDangerParty[i] = 0;
		}
	}
	for (int i = M; i > 0; --i) {
		bool b = false;
		for (auto x : party[i]) {
			if (i < minDangerParty[x]) {
				b = true;
				break;
			}
		}
		if (b) {
			for (auto x : party[i]) {
				if (i >= minDangerParty[x]) {
					minDangerParty[x] = i + 1;
					if (lastParty[x] < i + 1) {
						cout << "NO";
						return 0;
					}
				}
			}
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= N; ++i) {
		cout << ((minDangerParty[i] == 0) ? '1' : '0') << ' ';
	}
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;
char dna[4]{ 'A', 'C', 'G', 'T' };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, dist = 0;
	cin >> N >> M;
	vector<string> v(N);
	for (int i = 0; i != N; ++i)
		cin >> v[i];
	for (int j = 0; j != M; ++j) {
		int cnt[4]{ 0, 0, 0, 0 };
		int mx = 0;
		char ch;
		for (int i = 0; i != N; ++i) {
			switch (v[i][j]) {
			case 'A':
				++cnt[0];
				break;
			case 'C':
				++cnt[1];
				break;
			case 'G':
				++cnt[2];
				break;
			case 'T':
				++cnt[3];
			}
		}
		for (int k = 0; k != 4; ++k) {
			if (mx < cnt[k]) {
				mx = cnt[k];
				ch = dna[k];
			}
		}
		cout << ch;
		dist += N - mx;
	}
	cout << '\n' << dist;
}
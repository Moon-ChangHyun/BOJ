#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	for (cin >> T; ~--T; ) {
		int N, M, ret = 0;
		long long sumA = 0, sumB = 0;
		double avgA, avgB;
		cin >> N >> M;
		vector<int> studC(N);
		for (int i = 0; i != N; ++i) {
			cin >> studC[i];
			sumA += studC[i];
		}
		avgA = sumA / (double)N;
		for (int i = 0; i != M; ++i) {
			int x;
			cin >> x;
			sumB += x;
		}
		avgB = sumB / (double)M;
		for (int i = 0; i != N; ++i) {
			if (studC[i] < avgA && studC[i] > avgB)
				++ret;
		}
		cout << ret << '\n';
	}
}
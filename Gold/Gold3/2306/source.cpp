// 48ms, 3000KB

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, dp[500][500];
string dna;

int maxLenInRange(int l, int r) {
	if (l > r) return 0;
	int& ret = dp[l][r];
	if (ret != -1) return ret;
	int firstA = l, firstG = l;
	do {
		if (dna[firstA] == 'a') break;
		++firstA;
	} while (firstA <= r);
	do {
		if (dna[firstG] == 'g') break;
		++firstG;
	} while (firstG <= r);
	ret = 0;
	if (firstA < r) {
		for (int idxT = firstA + 1; idxT <= r; ++idxT) {
			if (dna[idxT] == 't') {
				ret = max(ret, 2 + maxLenInRange(firstA + 1, idxT - 1) + maxLenInRange(idxT + 1, r));
			}
		}
	}
	if (firstG < r) {
		for (int idxC = firstG + 1; idxC <= r; ++idxC) {
			if (dna[idxC] == 'c')
				ret = max(ret, 2 + maxLenInRange(firstG + 1, idxC - 1) + maxLenInRange(idxC + 1, r));
		}
	}
	return ret;
}

int main() {
	cin >> dna;
	n = dna.size();
	for (int i = 0; i < n; ++i) {
		dp[i][i] = 0;
		for (int j = i + 1; j < n; ++j) {
			dp[i][j] = -1;
		}
	}
	cout << maxLenInRange(0, n - 1);
}
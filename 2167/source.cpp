#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N = 0, M = 0;
	cin >> N >> M;
	vector <vector<int>> arr;
	arr.reserve(N);
	for (int i = 0; i != N; ++i) {
		vector<int> row;
		row.reserve(M);
		for (int j = 0; j != M; ++j) {
			int tmp;
			cin >> tmp;
			row.push_back(tmp);
		}
		arr.push_back(row);
	}
	int K;
	cin >> K;
	for (; K != 0; --K) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		int sum = 0;
		vector<vector<int>>::iterator row_end = next(arr.begin(), x);
		for (auto row = next(arr.begin(), i - 1); row != row_end; ++row) {
			vector<int>::iterator col_end = next(row->begin(), y);
			for (auto item = next(row->begin(), j - 1); item != col_end; ++item) {
				sum += *item;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
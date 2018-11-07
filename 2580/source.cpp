#include<cstdio>
#include<vector>
using namespace std;

int board[9][9];
int row[9], col[9], box[9];
vector<int> values;
vector<pair<int, int>> nullCell;
bool findAns = false;

void f(int ind) {
	if (findAns)
		return;
	if (ind == values.size()) {
		int iter = 0;
		for (int i = 0; i != 9; ++i) {
			for (int j = 0; j != 9; ++j) {
				printf("%d ", board[i][j] ? board[i][j] : values[iter++]);
			}
			printf("\n");
		}
		findAns = true;
	}
	else {
		int i = nullCell[ind].first, j = nullCell[ind].second;
		for (int k = 1; k <= 9; ++k) {
			if (!(row[i] & (1 << k))) {
				if ((col[j] & (1 << k)) || (box[(i / 3) * 3 + (j / 3)] & (1 << k)))
					continue;
				row[i] |= (1 << k);
				col[j] |= (1 << k);
				box[(i / 3) * 3 + (j / 3)] |= (1 << k);
				values[ind] = k;
				f(ind + 1);
				row[i] &= ~(1 << k);
				col[j] &= ~(1 << k);
				box[(i / 3) * 3 + (j / 3)] &= ~(1 << k);
				values[ind] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i != 9; ++i) {
		for (int j = 0; j != 9; ++j) {
			int x;
			scanf("%d", &x);
			if (!x)
				nullCell.push_back(make_pair(i, j));
			else {
				board[i][j] = x;
				row[i] |= (1 << x);
				col[j] |= (1 << x);
				box[(i / 3) * 3 + (j / 3)] |= (1 << x);
			}
		}
	}
	values.resize(nullCell.size());
	f(0);
}
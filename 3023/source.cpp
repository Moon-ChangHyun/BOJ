#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int R, C;
	scanf("%d%d", &R, &C);
	vector<vector<char>> v(R << 1, vector<char>(C << 1));
	for (int i = 0; i != R; ++i) {
		for (int j = 0; j != C; ++j) {
			scanf(" %c", &v[i][j]);
			v[(R << 1) - 1 - i][(C << 1) - 1 - j] = v[(R << 1) - 1 - i][j] = v[i][(C << 1) - 1 - j] = v[i][j];
		}
	}
	int a, b;
	scanf("%d%d", &a, &b);
	--a; --b;
	v[a][b] = '#' + '.' - v[a][b];
	for (auto row : v) {
		for (auto it : row)
			printf("%c", it);
		printf("\n");
	}
}
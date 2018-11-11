#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int>> matrix(n);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != m; ++j) {
			int x;
			scanf("%d", &x);
			matrix[i].push_back(x);
		}
	}
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != m; ++j) {
			int x;
			scanf("%d", &x);
			printf("%d ", matrix[i][j] + x);
		}
		printf("\n");
	}
}
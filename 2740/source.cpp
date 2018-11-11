#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int n, m, k;
	scanf("%d%d", &n, &m);
	vector<vector<int>> mat1(n, vector<int>(m));
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != m; ++j)
			scanf("%d", &mat1[i][j]);
	scanf("%d%d", &m, &k);
	vector<vector<int>> mat2(m, vector<int>(k));
	for (int i = 0; i != m; ++i)
		for (int j = 0; j != k; ++j)
			scanf("%d", &mat2[i][j]);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != k; ++j) {
			int sum = 0;
			for (int p = 0; p != m; ++p)
				sum += mat1[i][p] * mat2[p][j];
			printf("%d ", sum);
		}
		printf("\n");
	}
}
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, temp;
	scanf("%d", &N);
	vector<int> A(N);
	for (int i = 0; i != N; ++i)
		scanf("%d", &A[i]);
	sort(A.begin(), A.end());
	scanf("%d", &N);
	for (int i = 0; i != N; ++i) {
		scanf("%d", &temp);
		printf("%d\n", binary_search(A.begin(), A.end(), temp));
	}
}
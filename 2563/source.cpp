#include<cstdio>
using namespace std;
bool visit[100][100];
int main() {
	int n, ret = 0;
	scanf("%d", &n);
	for (int k = 0; k != n; ++k) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int i = a; i < a + 10; ++i)
			for (int j = b; j < b + 10; ++j)
				visit[i][j] = true;
	}
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (visit[i][j]) ++ret;
	printf("%d", ret);
}
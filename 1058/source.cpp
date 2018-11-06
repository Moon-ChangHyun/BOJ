#include<cstdio>
#include<algorithm>
using namespace std;
int N;
bool frd[51][51];
bool adj[51][51];
int main() {
	int ret = 0;
	scanf("%d", &N);
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != N; ++j) {
			char c;
			scanf(" %c", &c);
			if (c == 'Y')
				frd[i][j] = adj[i][j] = true;
		}
	}
	for (int i = 0; i != N; ++i)
		for (int j = 0; j != N; ++j)
			if (adj[i][j])
				for (int k = 0; k != N; ++k)
					if (adj[j][k])
						frd[k][i] = frd[i][k] = true;
	for (int i = 0; i != N; ++i) {
		int x = 0;
		for (int j = 0; j != N; ++j)
			if (frd[i][j]) ++x;
		ret = max(ret, x - 1);
	}
	printf("%d", ret);

}
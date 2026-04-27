// 16ms, 9584KB

#include<cstdio>
#include<algorithm>

using namespace std;

int n, m[100001], c[100001][5];
int dist[5][5] = { 
	{0, 2, 2, 2, 2},
	{0, 1, 3, 4, 3},
	{0, 3, 1, 3, 4},
	{0, 4, 3, 1, 3},
	{0, 3, 4, 3, 1}
};

int f(int x, int s) { //x는 인덱스, s는 다른발의 위치
	if (x == n) return 0;
	int& ret = c[x][s];
	if (ret) return ret;
	ret = dist[s][m[x]] + f(x + 1, m[x - 1]);
	if (m[x] != s) ret = min(ret, dist[m[x - 1]][m[x]] + f(x + 1, s));
	return ret;
}

int main() {
	while (true) {
		scanf("%d", m + n);
		if (!m[n++]) break;
	}
	--n;
    printf("%d", 2 + f(1, 0));
}
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int n, c, ret = 0;
	int fCnt[26] = { 0 };
	scanf("%d ", &n);
	while (true) {
		c = getchar();
		if (c == '\n')
			break;
		++fCnt[c - 'A'];
	}
	for (int i = 1; i < n; ++i) {
		int tCnt[26] = { 0 };
		while (true) {
			c = getchar();
			if (c == '\n' || c == EOF)
				break;
			++tCnt[c - 'A'];
		}
		int dist = 0;
		for (int j = 0; j != 26; ++j)
			dist += abs(fCnt[j] - tCnt[j]);
		if (dist <= 1)
			++ret;
		else if (dist == 2) {
			dist = 0;
			for (int j = 0; j != 26; ++j)
				dist += fCnt[j] - tCnt[j];
			if (dist == 0)
				++ret;
		}
	}
	printf("%d", ret);
}
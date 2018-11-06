#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int aCnt[26] = { 0 };
	int bCnt[26] = { 0 };
	char a[1001], b[1001];
	scanf("%s%s", a, b);
	for (int i = 0; a[i]; ++i)
		++aCnt[a[i] - 'a'];
	for (int i = 0; b[i]; ++i)
		++bCnt[b[i] - 'a'];
	int dist = 0;
	for (int i = 0; i != 26; ++i)
		dist += abs(aCnt[i] - bCnt[i]);
	printf("%d", dist);
}
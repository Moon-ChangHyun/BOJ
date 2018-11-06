#include<bitset>
#include<cstdio>
using namespace std;
int main() {
	int N, ret = 0;
	bitset<101> bs;
	for (scanf("%d", &N); ~--N; ) {
		int x;
		scanf("%d", &x);
		if (bs[x]) ++ret;
		else bs[x] = true;
	}
	printf("%d", ret);
}
// 4ms, 5144KB

#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int lcs[1001][1001];//a[i],b[j]까지 고려했을때 lcs길이
char a[1002], b[1002];
int main() {
	int i, j;
	scanf("%s %s", a + 1, b + 1);
	for(i = 1; a[i]; ++i) {
		for(j = 1; b[j]; ++j) {
			if(a[i] == b[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	printf("%d\n", lcs[i - 1][j - 1]);
	string ret;
	--i; --j;
	while(true) {
		if(i == 0 || j == 0) break;
		if(a[i] == b[j]) {
			ret.push_back(a[i]);
			--i; --j;
		}
		else {
			if(lcs[i - 1][j] > lcs[i][j - 1])
				--i;
			else
				--j;
		}
	}
	for(auto rIter = ret.rbegin(); rIter != ret.rend(); ++rIter)
		putchar(*rIter);
}
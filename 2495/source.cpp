#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	for (int t = 0; t != 3; ++t) {
		char buf[9];
		int ret = 1, cnt = 1;
		scanf("%s", buf);
		for (int i = 1; i <= 8; ++i) {
			if (buf[i - 1] == buf[i]) ++cnt;
			else {
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
		ret = max(ret, cnt);
		printf("%d\n", ret);
	}
}
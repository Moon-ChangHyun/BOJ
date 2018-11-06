#include<cstdio>
#include<array>
using namespace std;
int main() {
	int n, ret = 0;
	for (scanf("%d ", &n); ~--n;) {
		array<bool, 26> arr{ 0 };
		char pre = 0, cur;
		while (true) {
			cur = getchar();
			if (cur == '\n') {
				++ret;
				break;
			}
			if (cur != pre && pre) {
				arr[pre - 'a'] = true;
				if (arr[cur - 'a']) {
					while ('\n' != (cur = getchar()));
					break;
				}

			}
			pre = cur;
		}
	}
	printf("%d", ret);
}
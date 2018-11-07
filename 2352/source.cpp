#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, ret = 1;
	unsigned short arr[40001];
	arr[0] = 0;
	for (scanf("%d", &n); ~--n;) {
		unsigned short x;
		scanf("%hu", &x);
		if (arr[ret - 1] < x)
			arr[ret++] = x;
		else {
			auto iter = lower_bound(arr, arr + ret, x);
			*iter = x;
		}
	}
	printf("%d", --ret);
}
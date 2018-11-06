#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int l, n, psum = 0, ret = numeric_limits<int>::min();
	scanf("%d", &l);
	for (int i = 0; i != l; ++i) {
		scanf("%d", &n);
		psum = max(0, psum) + n;
		ret = max(ret, psum);
	}
	printf("%d", ret);
}
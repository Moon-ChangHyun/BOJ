#include<set>
#include<cstdio>
using namespace std;
int main() {
	int a, b, x, d = 0;
	set<int> sa;
	scanf("%d%d", &a, &b);
	for (int i = 0; i != a; ++i) {
		scanf("%d", &x);
		sa.insert(x);
	}
	for (int i = 0; i != b; ++i) {
		scanf("%d", &x);
		if (sa.find(x) != sa.end())
			++d;
	}
	printf("%d", a + b - 2 * d);
}
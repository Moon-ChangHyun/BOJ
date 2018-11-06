#include<cstdio>
#include<set>
using namespace std;
int main() {
	int n, a, b;
	multiset<pair<int, int>> ms;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		scanf("%d%d", &a, &b);
		ms.insert({ b, a });
	}
	a = b = 0;
	for (auto iter : ms) {
		if (iter.second >= a) {
			++b;
			a = iter.first;
		}
	}
	printf("%d", b);
}
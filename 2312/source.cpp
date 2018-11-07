#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); ~--t;) {
		int n;
		scanf("%d", &n);
		vector<pair<int, int>> v;
		for (int i = 2; n != 1; ++i) {
			int cnt = 0;
			while (!(n%i)) {
				n /= i;
				++cnt;
			}
			if (cnt)
				v.push_back({ i, cnt });
		}
		for (auto iter : v) {
			printf("%d %d\n", iter.first, iter.second);
		}
	}
}
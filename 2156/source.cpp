#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int c[10000][3];
int main() {
	int n, t;
	vector<int> v;
	scanf("%d", &n);
	v.reserve(n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &t);
		v.push_back(t);
	}
	function<int(int, int)> f = [&](int index, int con) {
		int& ret = c[index][con];
		if (ret) return ret;
		if (index == n - 1) {
			if (con == 2)
				return ret = 0;
			return ret = v[index];
		}
		if (con == 2) return ret = f(index + 1, 0);
		return ret = max(v[index] + f(index + 1, con + 1), f(index + 1, 0));
	};
	printf("%d", f(0, 0));
}
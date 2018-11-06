#include<cstdio>
#include<vector>
using namespace std;
int n, s;
vector<int> v;
int f(int p, int remain) {
	if (p == n) {
		if (remain) return 0;
		else return 1;
	}
	return f(p + 1, remain) + f(p + 1, remain - v[p]);
}
int main() {
	scanf("%d%d", &n, &s);
	v.resize(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	printf("%d", s ? f(0, s) : f(0, s) - 1);
}
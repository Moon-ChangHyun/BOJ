#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int n, x, k = 0;
	vector<int> v;
	scanf("%d", &n);
	v.reserve(n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i != n; ++i) {
		int t = v[i] - v[i - 1];
		if (k < t) {
			k ^= t;
			t ^= k;
			k ^= t;
		}
		k = gcd(k, t);
	}
	v.clear();
	int l = sqrt(k);
	for (int i = 2; i <= l; ++i)
		if (!(k%i)) {
			v.push_back(i);
			printf("%d ", i);
		}
	int i = v.size() - 1;
	if (v.back()*v.back() == k) --i;
	for (; i != -1; --i)
		printf("%d ", k / v[i]);
	printf("%d", k);
}
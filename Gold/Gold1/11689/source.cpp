// 8ms, 1228KB

#include<cstdio>
#include<vector>
using namespace std;

int main() {
	vector<long long> p;
	long long n, nd, i = 2, j = 1;
	scanf("%lld", &n);
	nd = n;
	while (true) {
		bool b = false;
		while (!(n % i)) {
			n /= i;
			b = true;
		}
		if (b) p.push_back(i);
		++i;
		if (i * i > n) {
			if(n != 1) p.push_back(n);
			break;
		}
	}
	for (auto k : p) {
		nd /= k;
		j *= (k - 1);
	}
	printf("%lld", j * nd);
}
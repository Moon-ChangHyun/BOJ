#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, x, t, asc = 1, desc = 1, al = 1, dl = 1;
	scanf("%d%d", &n, &x);
	for (int i = 1; i != n; ++i) {
		scanf("%d", &t);
		if (x == t) {
			++al;
			++dl;
		}
		else if (x < t) {
			++al;
			desc = max(dl, desc);
			dl = 1;
		}
		else {
			++dl;
			asc = max(al, asc);
			al = 1;
		}
		x = t;
	}
	asc = max(al, asc);
	desc = max(dl, desc);
	printf("%d", max(asc, desc));
}
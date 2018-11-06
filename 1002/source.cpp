#include <cstdio>
using namespace std;
int main() {
	int T;
	for (scanf("%d", &T); ~--T;) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		if (x1 == x2 && y1 == y2) {
			printf("%d\n", r1 == r2 ? -1 : 0);
			continue;
		}
		int dd = (x2 - x1) * (x2 - x1) + (y2 - y1)*(y2 - y1);
		int pr = (r1 + r2) * (r1 + r2);
		int mr = (r1 - r2) * (r1 - r2);
		if (dd > pr || dd < mr)
			printf("0\n");
		else if (dd == pr || dd == mr)
			printf("1\n");
		else
			printf("2\n");
	}
}
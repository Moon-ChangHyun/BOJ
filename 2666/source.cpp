#include<cstdio>
#include<algorithm>
using namespace std;

int order[21], c[21][21][21];
int p1, p2, n, l;

int f(int op1, int op2, int x) {
	if (x == l)
		return min(abs(op1 - order[x]), abs(op2 - order[x]));
	int& ret = c[op1][op2][x];
	if (ret) return ret;
	return ret = min(abs(op1 - order[x]) + f(order[x], op2, x + 1), abs(op2 - order[x]) + f(op1, order[x], x + 1));
}

int main() {
	scanf("%d%d%d%d", &n, &p1, &p2, &l);
	for (int i = 1; i <= l; ++i) scanf("%d", order + i);
	printf("%d", f(p1, p2, 1));
}
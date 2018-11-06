#include<cstdio>
int main() {
	int t = 0, o, w;
	while (true) {
		scanf("%d%d", &o, &w);
		if (o == 0 && w == 0) break;
		char op;
		int val;
		bool dead = false;
		while (true) {
			scanf(" %c%d", &op, &val);
			if (op == '#') break;
			if (op == 'F')
				w += val;
			else {
				w -= val;
				if (w <= 0) dead = true;
			}
		}
		printf("%d ", ++t);
		if (dead)
			printf("RIP\n");
		else if ((o >> 1) < w && w < (o << 1))
			printf(":-)\n");
		else
			printf(":-(\n");
	}
}
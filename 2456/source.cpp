#include<cstdio>
#include<algorithm>
using namespace std;
int a[3], b[3], c[3];
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &x);
		++a[x - 1];
		scanf("%d", &x);
		++b[x - 1];
		scanf("%d", &x);
		++c[x - 1];
	}
	int as = a[0] + a[1] * 2 + a[2] * 3;
	int bs = b[0] + b[1] * 2 + b[2] * 3;
	int cs = c[0] + c[1] * 2 + c[2] * 3;
	if (as > bs) {
		if (cs > as) {
			printf("3 %d", cs);
		}
		else if (as > cs) {
			printf("1 %d", as);
		}
		else {
			if (a[2] > c[2]) {
				printf("1 %d", as);
			}
			else if (a[2] < c[2]) {
				printf("3 %d", cs);
			}
			else {
				if (a[1] > c[1]) {
					printf("1 %d", as);
				}
				else if (a[1] < c[1]) {
					printf("3 %d", cs);
				}
				else {
					printf("0 %d", as);
				}
			}
		}
	}
	else if (as < bs) {
		if (bs < cs) {
			printf("3 %d", cs);
		}
		else if (bs > cs) {
			printf("2 %d", bs);
		}
		else {
			if (b[2] > c[2]) {
				printf("2 %d", bs);
			}
			else if (b[2] < c[2]) {
				printf("3 %d", cs);
			}
			else {
				if (b[1] > c[1]) {
					printf("2 %d", bs);
				}
				else if (b[1] < c[1]) {
					printf("3 %d", cs);
				}
				else {
					printf("0 %d", bs);
				}
			}
		}
	}
	else {
		if (as < cs) {
			printf("3 %d", cs);
		}
		else if (as > cs) {
			if (a[2] > b[2]) {
				printf("1 %d", as);
			}
			else if (a[2] < b[2]) {
				printf("2 %d", bs);
			}
			else {
				if (a[1] > b[1]) {
					printf("1 %d", as);
				}
				else if (a[1] < b[1]) {
					printf("2 %d", bs);
				}
				else {
					printf("0 %d", as);
				}
			}
		}
		else {
			if (a[2] > b[2]) {
				if (c[2] > a[2]) {
					printf("3 %d", cs);
				}
				else if (c[2] < a[2]) {
					printf("1 %d", as);
				}
				else {
					if (a[1] > c[1]) {
						printf("1 %d", as);
					}
					else if (a[1] < c[1]) {
						printf("3 %d", cs);
					}
					else {
						printf("0 %d", as);
					}
				}
			}
			else if (a[2] < b[2]) {
				if (c[2] > b[2]) {
					printf("3 %d", cs);
				}
				else if (c[2] < b[2]) {
					printf("2 %d", bs);
				}
				else {
					if (b[1] > c[1]) {
						printf("2 %d", bs);
					}
					else if (b[1] < c[1]) {
						printf("3 %d", cs);
					}
					else {
						printf("0 %d", bs);
					}
				}
			}
			else {
				if (b[2] > c[2]) {
					if (a[1] > b[1]) {
						printf("1 %d", as);
					}
					else if (a[1] < b[1]) {
						printf("2 %d", bs);
					}
					else {
						printf("0 %d", as);
					}
				}
				else if (b[2] < c[2]) {
					printf("3 %d", cs);
				}
				else {
					if (a[1] > b[1]) {
						if (c[1] > a[1]) {
							printf("3 %d", cs);
						}
						else if (c[1] < a[1]) {
							printf("1 %d", as);
						}
						else {
							printf("0 %d", as);
						}
					}
					else if (a[1] < b[1]) {
						if (b[1] < c[1]) {
							printf("3 %d", cs);
						}
						else if (b[1] > c[1]) {
							printf("2 %d", bs);
						}
						else {
							printf("0 %d", bs);
						}
					}
					else {
						if (a[1] < c[1]) {
							printf("3 %d", cs);
						}
						else {
							printf("0 %d", as);
						}
					}
				}
			}
		}
	}
}
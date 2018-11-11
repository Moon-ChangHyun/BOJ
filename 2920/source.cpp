#include<cstdio>
int main() {
	int a[8];
	for (int i = 0; i != 8; ++i) scanf("%d", a + i);
	if (a[0] == 1) {
		bool b = true;
		for (int i = 1; i != 8; ++i)
			if (a[i] != i + 1) b = false;
		if (b) printf("ascending");
		else printf("mixed");
	}
	else if (a[0] == 8) {
		bool b = true;
		for (int i = 1; i != 8; ++i)
			if (a[i] != 8 - i) b = false;
		if (b) printf("descending");
		else printf("mixed");
	}
	else
		printf("mixed");
}
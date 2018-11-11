#include<cstdio>
int sizeA, sizeB;
int main() {
	int ret = 0;
	while (getchar() != '\n') ++sizeA;
	if (getchar() == '*') {
		getchar();
		while (getchar() != '\n') ++sizeB;
		printf("1");
		for (int i = sizeA + sizeB - 2; i != 0; --i) printf("0");
	}
	else {
		getchar();
		while (getchar() != '\n') ++sizeB;
		if (sizeA < sizeB) {
			sizeA ^= sizeB;
			sizeB ^= sizeA;
			sizeA ^= sizeB;
		}
		if (sizeA == sizeB) {
			printf("2");
			for (int i = sizeA - 1; i != 0; --i) printf("0");
		}
		else {
			printf("1");
			for (int i = sizeA - 1; i != sizeB; --i) printf("0");
			printf("1");
			for (int i = sizeB - 1; i != 0; --i) printf("0");
		}
	}
}
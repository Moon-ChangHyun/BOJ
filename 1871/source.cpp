#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int N;
	for (scanf("%d", &N); ~--N; ) {
		char str[9];
		scanf("%s", str);
		int a = (str[0] - 'A') * 676 + (str[1] - 'A') * 26 + (str[2] - 'A');
		int b = (str[4] & 0xf) * 1000 + (str[5] & 0xf) * 100 + (str[6] & 0xf) * 10 + (str[7] & 0xf);
		if (abs(a - b) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}
}
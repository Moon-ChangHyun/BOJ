#include<cstdio>
int main() {
	char c;
	double ret;
	scanf("%c", &c);
	if (c == 'F')
		ret = 0;
	else {
		ret = 4 - c + 'A';
		scanf("%c", &c);
		if (c == '+')
			ret += 0.3;
		else if (c == '-')
			ret -= 0.3;
	}
	printf("%.1f", ret);
}
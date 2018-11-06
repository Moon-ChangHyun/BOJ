#include<cstdio>
using namespace std;

char str[51];
int close[51];
int stack[51];
int top = 0;
int uzip(int s, int e) {
	int len = 0;
	for (int i = s; i < e; ++i) {
		if (str[i] == '(') {
			--len;
			len += uzip(i + 1, close[i]) * (str[i - 1] & 0xF);
			i = close[i];
		}
		else
			++len;
	}
	return len;
}

int main() {
	scanf("%s", str);
	int l;
	for (l = 0; str[l]; ++l) {
		if (str[l] == '(')
			stack[top++] = l;
		else if (str[l] == ')')
			close[stack[--top]] = l;
	}
	printf("%d", uzip(0, l));
}
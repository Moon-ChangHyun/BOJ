#include<cstdio>
int main() {
	int n, top = 0;
	char cmd[101];
	double st[50];
	int input[26];
	scanf("%d%s", &n, cmd);
	for (int i = 0; i != n; ++i)
		scanf("%d", input + i);
	for (int i = 0; cmd[i]; ++i) {
		if ('A' <= cmd[i] && cmd[i] <= 'Z')
			st[top++] = (double)input[cmd[i] - 'A'];
		else {
			top -= 2;
			if (cmd[i] == '*')
				st[top] *= st[top + 1];
			else if (cmd[i] == '/')
				st[top] /= st[top + 1];
			else if (cmd[i] == '+')
				st[top] += st[top + 1];
			else if (cmd[i] == '-')
				st[top] -= st[top + 1];
			++top;
		}
	}
	double ret = st[top - 1];
	printf("%.02f", ret);
}
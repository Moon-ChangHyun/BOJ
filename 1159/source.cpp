#include<cstdio>
int cnt[26];
int main() {
	int n;
	for (scanf("%d ", &n); ~--n; ) {
		char c = getchar();
		++cnt[c - 'a'];
		while ('\n' != getchar());
	}
	int ret = 0;
	for (int i = 0; i != 26; ++i)
		if (cnt[i] >= 5) ++ret;
	if (!ret)
		printf("PREDAJA");
	else
		for (int i = 0; i != 26; ++i)
			if (cnt[i] >= 5) printf("%c", 'a' + i);
}
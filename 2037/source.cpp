#include<cstdio>
int main() {
	int group[26]{ 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7 };
	int cnt[26]{ 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };
	int p, w, ret = 0;
	char str[1000];
	scanf("%d%d", &p, &w);
	scanf(" %[^\n]s", str);
	int preGroup = -1;
	for (int i = 0; str[i]; ++i) {
		if (str[i] == ' ') {
			ret += p;
			preGroup = -1;
		}
		else {
			int grp = group[str[i] - 'A'];
			if (preGroup == grp) ret += w;
			ret += cnt[str[i] - 'A'] * p;
			preGroup = grp;
		}
	}
	printf("%d", ret);
}
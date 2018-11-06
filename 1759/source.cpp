#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int C, L;
char cp[16];
vector<char> characters;

bool isVowel(char c) {
	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	}
	return false;
}

void dfs(int p, int l, int vowelNum) {
	if (l == L) {
		if (vowelNum != 0 && vowelNum <= L - 2) {
			for (int i = 0; i != l; ++i)
				putchar(cp[i]);
			putchar('\n');
		}
		return;
	}
	for (int i = p; i < C; ++i) {
		cp[l] = characters[i];
		if (isVowel(cp[l]))
			dfs(i + 1, l + 1, vowelNum + 1);
		else
			dfs(i + 1, l + 1, vowelNum);
	}
}

int main() {
	scanf("%d%d", &L, &C);
	characters.resize(C);
	for (auto& iter : characters)
		scanf(" %c", &iter);
	sort(characters.begin(), characters.end());
	dfs(0, 0, 0);
}
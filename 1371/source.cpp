#include<cstdio>
#include<algorithm>
using namespace std;
int alpha[26];
int main() {
	int mx = 0;
	char c;
	while (true) {
		if (scanf("%c", &c) == EOF) break;
		if (c != ' ' && c != '\n')
			mx = max(mx, ++alpha[c - 'a']);
	}
	for (int i = 0; i != 26; ++i)
		if (alpha[i] == mx)
			printf("%c", i + 'a');
}
#include <cstdio>
int arr[26];
int main() {
	char c;
	while (true) {
		c = getchar();
		if (c == '\n')
			break;
		c -= c >= 'a' ? 'a' : 'A';
		++arr[c];
	}
	int max = 0;
	bool b = false;
	for (int i = 1; i != 26; ++i) {
		if (arr[max] < arr[i]) {
			max = i;
			b = false;
		}
		else if (arr[max] == arr[i])
			b = true;
	}
	printf("%c", b ? '?' : max + 'A');
}
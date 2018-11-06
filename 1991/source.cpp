#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int pos[26]{ 1 };
vector<char> v;

void preorder(int num) {
	if (num >= v.size() || v[num] == 0)
		return;
	putchar(v[num]);
	preorder(num << 1);
	preorder((num << 1) + 1);
}

void inorder(int num) {
	if (num >= v.size() || v[num] == 0)
		return;
	inorder(num << 1);
	putchar(v[num]);
	inorder((num << 1) + 1);
}

void postorder(int num) {
	if (num >= v.size() || v[num] == 0)
		return;
	postorder(num << 1);
	postorder((num << 1) + 1);
	putchar(v[num]);
}

int main() {
	int n, m = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i != n; ++i) {
		char a, b, c;
		a = getchar();
		getchar();
		b = getchar();
		getchar();
		c = getchar();
		getchar();
		if (b != '.') {
			pos[b - 'A'] = pos[a - 'A'] << 1;
			m = max(m, pos[b - 'A']);
		}
		if (c != '.') {
			pos[c - 'A'] = (pos[a - 'A'] << 1) + 1;
			m = max(m, pos[c - 'A']);
		}
	}
	v.resize(m + 1);
	for (int i = 0; i != 26; ++i) {
		v[pos[i]] = i + 'A';
	}
	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	postorder(1);
}
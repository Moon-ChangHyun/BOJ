#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int N, K, idx = 0;
	bool b = true;
	scanf("%d%d", &N, &K);
	vector<char> v(N, '?');
	vector<bool> visit(26, false);
	for (int i = 0; i != K; ++i) {
		int cnt;
		char ch;
		scanf("%d %c", &cnt, &ch);
		idx = (idx + cnt) % N;
		if (v[idx] == '?') {
			if (visit[ch - 'A']) b = false;
			visit[ch - 'A'] = true;
			v[idx] = ch;
		}
		else if (v[idx] != ch)
			b = false;
	}
	if (!b) printf("!");
	else {
		printf("%c", v[idx]);
		for (int i = (idx + N - 1) % N; i != idx; i = (i + N - 1) % N)
			printf("%c", v[i]);
	}
}
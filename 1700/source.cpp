#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	int N, K, ret = 0;
	scanf("%d%d", &N, &K);
	vector<int> schedule(K);
	vector<queue<int>> v(K + 1);
	vector<bool> use(K + 1, false);
	for (int i = 0; i != K; ++i) {
		scanf("%d", &schedule[i]);
		v[schedule[i]].push(i);
	}
	int remain = N;
	int i;
	for (i = 0; i != K; ++i) {
		if (remain == 0) break;
		if (!use[schedule[i]]) {
			use[schedule[i]] = true;
			--remain;
		}
		v[schedule[i]].pop();
	}
	if (i == K) printf("0");
	else {
		for (; i != K; ++i) {
			if (!use[schedule[i]]) {
				int last = i;
				for (int j = 0; j != K; ++j) {
					if (j == schedule[i]) continue;
					if (use[j]) {
						if (v[j].empty()) {
							use[j] = false;
							use[schedule[i]] = true;
							++ret;
							break;
						}
						last = max(last, v[j].front());
					}
				}
				if (!use[schedule[i]]) {
					use[schedule[last]] = false;
					use[schedule[i]] = true;
					++ret;
				}
			}
			v[schedule[i]].pop();
		}
		printf("%d", ret);
	}
}
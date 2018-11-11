#include<cstdio>
#include<map>
using namespace std;
int h1[500001], h2[500001];
int main() {
	int N, H;
	scanf("%d%d", &N, &H);
	for (int i = N / 2; i; --i) {
		int a, b;
		scanf("%d%d", &a, &b);
		++h1[a];
		++h2[b];
	}
	for (int i = H - 1; i; --i) {
		h1[i] += h1[i + 1];
		h2[i] += h2[i + 1];
	}
	map<int, int> mp;
	for (int i = 1; i <= H; ++i) {
		auto at = mp.insert({ h1[i] + h2[H - i + 1], 1 });
		if (!at.second)
			at.first->second++;
	}
	printf("%d %d", mp.begin()->first, mp.begin()->second);
}
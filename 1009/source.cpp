#include<cstdio>
#include<vector>
#include<array>
using namespace std;
int main() {
	int T, a, b;
    array<vector<int>, 10> arr {{{0}, {1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6}, {5}, {6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1}}};
	for (scanf("%d", &T); ~--T; ) {
		scanf("%d%d", &a, &b);
		a %= 10;
		int index = (b % arr[a].size()) - 1;
		if (index == -1) index = arr[a].size() - 1;
		int ret = arr[a][index];
		if (!ret) ret = 10;
		printf("%d\n", ret);
	}
}
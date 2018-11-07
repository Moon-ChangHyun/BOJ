#include<list>
#include<cstdio>
using namespace std;

pair<int, int> check(int ans, int comp) {
	pair<int, int> ret(0, 0);
	int arr1[3] = { ans / 100, (ans / 10) % 10, ans % 10 };
	int arr2[3] = { comp / 100, (comp / 10) % 10, comp % 10 };
	for (int i = 0; i != 3; ++i) {
		for (int j = 0; j != 3; ++j) {
			if (arr1[i] == arr2[j]) {
				if (i == j) ++ret.first;
				else ++ret.second;
				break;
			}
		}
	}
	return ret;
}
int main() {
	list<int> candNum;
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			for (int k = 1; k <= 9; ++k) {
				if (i == j || j == k || i == k) continue;
				candNum.push_back(i * 100 + j * 10 + k);
			}
		}
	}
	int N, ret;
	for (scanf("%d", &N); ~--N; ) {
		int num, st, bl;
		scanf("%d%d%d", &num, &st, &bl);
		for (auto iter = candNum.begin(); iter != candNum.end();) {
			auto result = check(*iter, num);
			if (result.first != st || result.second != bl) {
				candNum.erase(iter++);
			}
			else
				++iter;
		}
	}
	printf("%d", candNum.size());
}
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
	int N, M;
	char pN[21];
	cin >> N >> M;
	vector<string> v;
	unordered_map<string, int> h;
	v.reserve(N);
	for (int i = 0; i != N; ++i) {
		scanf("%s", pN);
		v.push_back(pN);
		h.insert({ pN, i + 1 });
	}
	int t;
	bool isInt;
	for (int i = 0; i != M; ++i) {
		isInt = scanf("%d", &t);
		if (isInt)
			printf("%s\n", v[t - 1].data());
		else {
			scanf("%s", pN);
			printf("%d\n", h[{pN}]);
		}
	}
}
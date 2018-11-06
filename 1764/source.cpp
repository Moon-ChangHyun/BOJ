#include<cstdio>
#include<string>
#include<unordered_set>
#include<set>
using namespace std;
int main() {
	int N, M;
	char buffer[21];
	scanf("%d%d", &N, &M);
	getchar();
	set<string> s;
	unordered_set<string> us;
	us.reserve(N);
	for (int i = 0; i != N; ++i) {
		scanf("%s", buffer);
		us.insert(buffer);
	}
	for (int i = 0; i != M; ++i) {
		scanf("%s", buffer);
		auto iter = us.find(buffer);
		if (us.find(buffer) != us.end()) s.insert(*iter);
	}
	printf("%d\n", s.size());
	for (auto iter : s)
		printf("%s\n", iter.data());
}
#include <iostream>
#include <set>
using namespace std;
int main() {
	int n, t;
	scanf("%d", &n);
	multiset<int> s;
	for (int i = 0; i != n; ++i) {
		scanf("%d", &t);
		s.insert(t);
	}
	multiset<int>::iterator iter;
	int sum = 0;
	while (1 < s.size()) {
		iter = s.begin();
		int preCards = *iter;
		s.erase(iter);
		iter = s.begin();
		preCards += *iter;
		sum += preCards;
		s.erase(iter);
		s.insert(preCards);
	}
	printf("%d", sum);
}
#include<iostream>
#include<set>
#include<string>
using namespace std;
int main() {
	auto cmp = [](string a, string b) {
		if (a.size() < b.size())
			return true;
		else if (a.size() > b.size())
			return false;
		return a < b;
	};
	set<string, decltype(cmp)> s(cmp);
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i != n; ++i) {
		string str;
		getline(cin, str);
		s.insert(str);
	}
	for (auto& iter : s)
		printf("%s\n", iter.data());
}
#include<map>
#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i != n; ++i) {
		string str;
		cin >> str;
		auto r = m.insert({ str, 0 });
		++(r.first->second);
	}
	string bestSeller;
	int num = 0;
	for (auto iter : m) {
		if (iter.second > num) {
			num = iter.second;
			bestSeller = iter.first;
		}
	}
	cout << bestSeller;
}
#include<iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, key;
	getline(cin, a);
	getline(cin, key);
	for (int i = 0; a[i]; ++i) {
		if (a[i] == ' ') continue;
		a[i] -= (1 + key[i % key.size()] - 'a');
		if (a[i] < 'a') a[i] += 26;
	}
	cout << a;
}
#include<string>
#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	while (true) {
		int ans = 0;
		getline(cin, str);
		if (str == "#") break;
		for (int i = 0; str[i]; ++i) {
			if ('A' <= str[i] && str[i] <= 'Z')
				str[i] += 32;
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				++ans;
		}
		cout << ans << '\n';
	}
}
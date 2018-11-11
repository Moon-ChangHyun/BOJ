#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<string> v;
	for (cin >> n; ~--n; ) {
		string str, num;
		cin >> str;
		for (int i = 0; str[i]; ++i) {
			if ('0' <= str[i] && str[i] <= '9')
				num += str[i];
			else {
				if (num != "") {
					int idx = num.find_first_not_of('0');
					if (idx == string::npos) v.push_back("0");
					else v.push_back(num.substr(idx));
					num.clear();
				}
			}
		}
		if (num != "") {
			int idx = num.find_first_not_of('0');
			if (idx == string::npos) v.push_back("0");
			else v.push_back(num.substr(idx));
			num.clear();
		}
	}
	sort(v.begin(), v.end(), [](string& lhs, string& rhs) -> bool {
		if (lhs.size() == rhs.size())
			return lhs < rhs;
		else
			return lhs.size() < rhs.size();
	});
	for (auto iter : v)
		cout << iter << '\n';
}
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> ret;
	for (int i = 0; i != 5; ++i) {
		string str;
		cin >> str;
		if (str.find("FBI") != string::npos)
			ret.push_back(i + 1);
	}
	if (ret.size() == 0)
		cout << "HE GOT AWAY!";
	else
		for (auto iter : ret)
			cout << iter << " ";
}
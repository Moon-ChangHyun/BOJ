#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int getres(string& str) {
	if (str == "black") return 0;
	if (str == "brown") return 1;
	if (str == "red") return 2;
	if (str == "orange") return 3;
	if (str == "yellow") return 4;
	if (str == "green") return 5;
	if (str == "blue") return 6;
	if (str == "violet") return 7;
	if (str == "grey") return 8;
	if (str == "white") return 9;
}
int main() {
	long long ret = 0;
	string s;
	cin >> s;
	ret += getres(s);
	ret *= 10;
	cin >> s;
	ret += getres(s);
	cin >> s;
	ret *= pow(10, getres(s));
	printf("%lld", ret);
}
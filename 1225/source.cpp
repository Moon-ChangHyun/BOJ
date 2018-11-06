#include<string>
#include<iostream>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	long long sumA = 0, sumB = 0;
	for (int i = 0; a[i]; ++i)
		sumA += (a[i] & 0xf);
	for (int i = 0; b[i]; ++i)
		sumB += (b[i] & 0xf);
	cout << sumA * sumB;
}
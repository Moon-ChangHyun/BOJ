#include<iostream>
using namespace std;
int main() {
	int X;
	cin >> X;
	int check = 64;
	int num = 0;
	while (X) {
		if (X >= check) {
			X -= check;
			num++;
		}
		check /= 2;
	}
	cout << num << endl;
	return 0;
}
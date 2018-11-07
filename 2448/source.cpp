#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> arr;
void f(int n, int y, int x) {
	if (n == 3) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
		return;
	}
	n >>= 1;
	f(n, y, x);
	f(n, y + n, x - n);
	f(n, y + n, x + n);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	arr.resize(n, string((n << 1) - 1, ' '));
	f(n, 0, n - 1);
	for (int i = 0; i != n; ++i)
		cout << arr[i] << '\n';
}
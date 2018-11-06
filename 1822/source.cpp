#include<set>
#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int nA, nB;
	cin >> nA >> nB;
	set<int> A;
	for (int i = 0; i != nA; ++i) {
		int x;
		cin >> x;
		A.insert(x);
	}
	for (int i = 0; i != nB; ++i) {
		int x;
		cin >> x;
		A.erase(x);
	}
	cout << A.size() << '\n';
	for (auto iter : A)
		cout << iter << ' ';
}
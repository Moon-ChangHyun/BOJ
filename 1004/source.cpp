#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i != T; ++i) {
		int ret = 0;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n;
		cin >> n;
		for (int j = 0; j != n; ++j) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			if (((cx - x1)*(cx - x1) + (cy - y1)*(cy - y1) < r*r) ^ ((cx - x2)*(cx - x2) + (cy - y2)*(cy - y2) < r*r))
				ret++;
		}
		cout << ret << endl;
	}
}
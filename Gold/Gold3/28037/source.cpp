// 4ms, 2184KB

#include<iostream>
#include<cmath>
#include<numbers>
#include<iomanip>

using namespace std;

constexpr double pi = numbers::pi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	for (cin >> T; ~--T;) {
		int before, after;
		double a, b, c;
		cin >> before >> after;
		cin >> a >> b >> c;
		cout << setprecision(9);
		if (a == 0 && b == 0 && c == 0)
			cout << a << ' ' << b << ' ' << c;
		else if (before == 1) {
			if (after == 2) { // 직교->원통
				double r = sqrt(a * a + b * b);
				double ac = acos(a / r);
				double as = asin(b / r);
				double phi;
				if (as < 0) //3~4사분면
					phi = 2 * pi - ac;
				else //1~2사분면
					phi = ac;
				cout << r << ' ' << phi << ' ' << c;
			}
			else { //직교->구면
				double r = sqrt(a * a + b * b + c * c);
				double theta = acos(c / r);
				double r2d = sqrt(a * a + b * b);
				double ac = acos(a / r2d);
				double as = asin(b / r2d);
				double phi;
				if (as < 0)
					phi = 2 * pi - ac;
				else
					phi = ac;
				cout << r << ' ' << theta << ' ' << phi;
			}
		}
		else if (before == 2) {
			if (after == 1) { // 원통->직교
				cout << a * cos(b) << ' ' << a * sin(b) << ' ' << c;
			}
			else { //원통->구면
				double r = sqrt(a * a + c * c);
				cout << r << ' ' << acos(c / r) << ' ' << b;
			}
		}
		else {
			if (after == 1) { //구면->직교
				double r = a * sin(b);
				cout << r * cos(c) << ' ' << r * sin(c) << ' ' << a * cos(b);
			}
			else { //구면->원통
				cout << a * sin(b) << ' ' << c << ' ' << a * cos(b);
			}
		}
		cout << '\n';
	}
}
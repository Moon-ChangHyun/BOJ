#include<iostream>
#include<queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	for (cin >> T; ~--T; ) {
		int M;
		cin >> M;
		cout << ((M + 1) >> 1);
		priority_queue<int> leftQ, rightQ;
		for (int i = 0; i != M; ++i) {
			int x;
			cin >> x;
			if (leftQ.size() == rightQ.size())
				leftQ.push(x);
			else
				rightQ.push(-x);
			if (!rightQ.empty() && leftQ.top() > -rightQ.top()) {
				int a = leftQ.top(); leftQ.pop();
				int b = -rightQ.top(); rightQ.pop();
				leftQ.push(b);
				rightQ.push(-a);
			}
			if (i % 20 == 0)
				cout << '\n';
			if (!(i & 1))
				cout << leftQ.top() << ' ';
		}
		cout << '\n';
	}
}
// 532ms, 3016KB

#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int stk[100000], top = 0;
	int T;
	for (cin >> T; ~--T;) {
		int n, ret = 0;
		cin >> n;
		vector<int> v(n + 1);
		vector<bool> visit(n + 1, false);
		vector<bool> finish(n + 1, false);
		for (int i = 1; i<= n; ++i)
			cin >> v[i];
		for (int i = 1; i <= n; ++i) {
			if (finish[i]) continue;
			int val = i;
			while (!visit[val]) {
				visit[val] = true;
				stk[top++] = val;
				val = v[val];
			}
			if (!finish[val]) {
				while (stk[--top] != val) {
					finish[stk[top]] = true;
				}
				finish[stk[top]] = true;
			}
			ret += top;
			while (top) {
				finish[stk[--top]] = true;
			}
		}
		cout << ret << '\n';
	}
}
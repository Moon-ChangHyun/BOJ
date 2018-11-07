#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> height(N + 1), answer(N + 1);
	height[0] = 100000001;
	for (int i = 1; i <= N; ++i) cin >> height[i];
	stack<int> st;
	for (int i = N; ~i; --i) {
		while (!st.empty() && height[st.top()] < height[i]) {
			answer[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	for (int i = 1; i <= N; ++i) cout << answer[i] << ' ';
}
#include<iostream>
#include<queue>
#include<functional>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int> leftHeap;
	priority_queue<int, vector<int>, greater<>> rightHeap;
	for (int i = 0; i != N; ++i) {
		int x;
		cin >> x;
		if (i % 2) rightHeap.push(x);
		else leftHeap.push(x);
		if (i > 0 && rightHeap.top() < leftHeap.top()) {
			int a = rightHeap.top(); rightHeap.pop();
			int b = leftHeap.top(); leftHeap.pop();
			leftHeap.push(a);
			rightHeap.push(b);
		}
		cout << leftHeap.top() << '\n';
	}
}
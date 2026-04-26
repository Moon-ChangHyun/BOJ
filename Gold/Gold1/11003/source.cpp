// 1492ms, 42412KB

#include<iostream>
#include<deque>
using namespace std;

int arr[5000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, L;
	cin >> N >> L;
	deque<int> dq;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		if (!dq.empty() && dq.front() == i - L)
			dq.pop_front();
		while (!dq.empty() && arr[dq.back()] >= arr[i])
			dq.pop_back();
		dq.push_back(i);
		cout << arr[dq.front()] << ' ';
	}
}
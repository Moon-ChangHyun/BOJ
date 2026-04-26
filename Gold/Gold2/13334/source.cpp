// 40ms, 30692KB

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, L;
pair<int, int> lines[100000]; // e, s

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> lines[i].first >> lines[i].second;
		if (lines[i].second > lines[i].first) {
			int tmp = lines[i].first;
			lines[i].first = lines[i].second;
			lines[i].second = tmp;
		}
	}
	cin >> L;
	sort(lines, lines + N);
	int answer = 0;
	priority_queue<int> pq;
	for (int i = 0; i < N; ++i) {
		while (!pq.empty() && -pq.top() < lines[i].first - L)
			pq.pop();
		if (lines[i].second >= lines[i].first - L) {
			pq.push(-lines[i].second);
			answer = max(answer, (int)pq.size());
		}
	}
	cout << answer;
}
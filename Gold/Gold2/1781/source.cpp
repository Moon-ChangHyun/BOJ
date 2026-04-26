// 64ms, 6040KB

#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using ll = long long;

int N;
vector<int> deadline;
vector<int> reward;
vector<int> sortByDeadline;

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	deadline.resize(N);
	reward.resize(N);
	sortByDeadline.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> deadline[i] >> reward[i];
		sortByDeadline[i] = i;
	}
	sort(sortByDeadline.begin(), sortByDeadline.end(), [](int u, int v) {
		return deadline[u] < deadline[v];
	});

	priority_queue<int, vector<int>, greater<>> pq; //컵라면 수 오름차순
	for (auto x : sortByDeadline) {
		if (pq.size() < deadline[x]) {
			pq.push(reward[x]);
		}
		else if (pq.top() < reward[x]) {
			pq.pop();
			pq.push(reward[x]);
		}
	}

	ll ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}
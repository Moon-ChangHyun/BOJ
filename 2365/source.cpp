#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int N, dN, S;
vector<vector<int>> cap, flow;
bool canFill(int maxCap) {
	for (int i = 0; i <= dN + 1; ++i)
		for (int j = 0; j <= dN + 1; ++j)
			flow[i][j] = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = N + 1; j <= dN; ++j)
			cap[i][j] = maxCap;
	int totalFlow = 0;
	while (true) {
		vector<int> parent(dN + 2, -1);
		stack<int> st;
		parent[0] = 0;
		st.push(0);
		while (!st.empty() && parent[dN + 1] == -1) {
			int here = st.top(); st.pop();
			for (int there = 0; there <= dN + 1; ++there) {
				if (cap[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					st.push(there);
					parent[there] = here;
				}
			}
		}
		if (parent[dN + 1] == -1) break;
		int amount = maxCap;
		for (int p = dN + 1; p; p = parent[p])
			amount = min(cap[parent[p]][p] - flow[parent[p]][p], amount);
		for (int p = dN + 1; p; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow == S;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int lo = 0, hi = 0;
	cin >> N;
	dN = (N << 1);
	cap.resize(dN + 2, vector<int>(dN + 2, 0));
	flow.resize(dN + 2, vector<int>(dN + 2));
	for (int i = 1; i <= N; ++i) {
		cin >> cap[0][i];
		hi = max(hi, cap[0][i]);
		S += cap[0][i];
	}
	for (int i = N + 1; i <= dN; ++i) {
		cin >> cap[i][dN + 1];
		hi = max(hi, cap[i][dN + 1]);
	}
	while (lo + 1 != hi) {
		int mid = (lo + hi) >> 1;
		if (canFill(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi << '\n';
	canFill(hi);
	for (int row = 1; row <= N; ++row) {
		for (int col = N + 1; col <= dN; ++col)
			cout << flow[row][col] << ' ';
		cout << '\n';
	}
}
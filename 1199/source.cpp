#include<iostream>
#include<vector>
using namespace std;
int N;
vector<vector<int>> adj;
vector<int> degree;
vector<int> circuit;

void getEulerCircuit(int here) {
	for (int there = 1; there <= N; ++there) {
		while (adj[here][there] > 0) {
			--adj[here][there];
			--adj[there][here];
			getEulerCircuit(there);
		}
	}
	circuit.push_back(here);
}

int main() {
	bool existEulerCircuit = true;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	adj.resize(N + 1, vector<int>(N + 1));
	degree.resize(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> adj[i][j];
			degree[i] += adj[i][j];
		}
		if (degree[i] % 2) existEulerCircuit = false;
	}
	if (!existEulerCircuit) cout << -1;
	else {
		getEulerCircuit(1);
		for (auto iter : circuit) cout << iter << ' ';
	}
}
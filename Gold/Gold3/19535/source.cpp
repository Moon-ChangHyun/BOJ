// 76ms, 5500KB

#include<iostream>
using namespace std;
int n, degree[300001];
pair<int, int> edge[300000];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		++degree[u];
		++degree[v];
		edge[i] = { u, v };
	}
	long long d = 0, g = 0;
	for (int i = 1; i <= n; ++i) {
		long long a = degree[i];
		if (a >= 3) g += (a * (a - 1) * (a - 2)) / 6;
	}
	for (int i = 1; i < n; ++i) {
		long long a = degree[edge[i].first];
		long long b = degree[edge[i].second];
		if (a >= 2 && b >= 2) d += (a - 1) * (b - 1);
	}
	if (d > g * 3)
		cout << 'D';
	else if (d < g * 3)
		cout << 'G';
	else
		cout << "DUDUDUNGA";
}
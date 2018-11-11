#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int N;
set<int> ret;
vector<int> v;
vector<bool> visit;

bool dfs(int obj, int num) {
	if (obj == num) {
		ret.insert(obj);
		return true;
	}
	if (visit[num]) return false;
	visit[num] = true;
	if (dfs(obj, v[num])) {
		ret.insert(num);
		return true;
	}
	return false;
}

void func(int num) {
	if (ret.find(num) != ret.end()) return;
	for (int i = 1; i <= N; ++i) visit[i] = false;
	int x = v[num];
	dfs(num, x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.resize(N + 1);
	visit.resize(N + 1, false);
	for (int i = 1; i <= N; ++i) {
		if (i == v[i]) ret.insert(i);
		cin >> v[i];
	}
	for (int i = 1; i <= N; ++i)
		func(i);
	cout << ret.size() << '\n';
	for (auto iter : ret)
		cout << iter << '\n';
}
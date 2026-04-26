// 52ms, 3200KB

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> catPoint;
vector<int> indCR, lis;
int N, M, T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> T;
	catPoint.reserve(T);
	for (int i = 0; i < T; ++i) {
		int r, c;
		cin >> r >> c;
		if (r <= N && c <= M)
			catPoint.emplace_back(r, c);
	}
	T = catPoint.size();
	indCR.resize(T);
	for (int i = 0; i < T; ++i)
		indCR[i] = i;
	sort(catPoint.begin(), catPoint.end());
	sort(indCR.begin(), indCR.end(), [](int a, int b) {
		return pair<int, int> {catPoint[a].second, catPoint[a].first} < pair<int, int>{catPoint[b].second, catPoint[b].first};
	});
	lis.push_back(indCR[0]);
	for (int i = 1; i < T; ++i)
	{
		if (lis.back() < indCR[i])
			lis.push_back(indCR[i]);
		else {
			auto iter = lower_bound(lis.begin(), lis.end(), indCR[i]);
			*iter = indCR[i];
		}
	}
	cout << lis.size();
}
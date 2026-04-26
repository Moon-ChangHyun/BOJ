// 356ms, 11440KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<pair<int, int>> range;
vector<int> numSortByL, numSortByR, lis;
int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	range.resize(N);
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		cin >> range[num - 1].first >> range[num - 1].second;
	}
	sort(range.begin(), range.end());
	range.erase(unique(range.begin(), range.end()), range.end());
	N = range.size();
	numSortByL.resize(N), numSortByR.resize(N);
	for (int i = 0; i < N; ++i)
		numSortByL[i] = numSortByR[i] = i;
	sort(numSortByL.begin(), numSortByL.end(), [](int a, int b) {
		if (range[a].first < range[b].first) return true;
		else if (range[a].first > range[b].first) return false;
		return range[a].second > range[b].second;
	});
	sort(numSortByR.begin(), numSortByR.end(), [](int a, int b) {
		if (range[a].second > range[b].second) return true;
		else if (range[a].second < range[b].second) return false;
		return range[a].first < range[b].first;
	});
	lis.push_back(numSortByL[numSortByR[0]]);
	for (int i = 1; i < N; ++i)
	{
		int val = numSortByL[numSortByR[i]];
		if (lis.back() < val)
			lis.push_back(val);
		else {
			auto iter = lower_bound(lis.begin(), lis.end(), val);
			*iter = val;
		}
	}
	cout << lis.size();
}
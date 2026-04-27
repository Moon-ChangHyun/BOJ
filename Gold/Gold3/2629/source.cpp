// 0ms, 3508KB

#include<iostream>
#include<vector>

using namespace std;

int N, total;
vector<int> weights;
vector<vector<char>> dp; //0미결, 1가능,-1불가능

char func(int idx, int target)
{
	if (idx == N)
		return target == total ? 1 : -1;
	char& ret = dp[idx][target];
	if (ret) return ret;
	if (func(idx + 1, target) == 1 || func(idx + 1, target + weights[idx]) == 1 || func(idx + 1, target - weights[idx]) == 1)
		return ret = 1;
	return ret = -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	weights.resize(N);
	for (auto& it : weights)
	{
		cin >> it;
		total += it;
	}
	dp.resize(N, vector<char>(total * 3));
	int t;
	for (cin >> t; ~--t;)
	{
		int W;
		cin >> W;
		if (W > total || func(0, W + total) == -1)
			cout << "N ";
		else
			cout << "Y ";
	}
}
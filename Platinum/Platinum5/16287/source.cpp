// 60ms, 2156KB

#include<iostream>
#include<vector>

using namespace std;

vector<bool> weightSumByTwo(400001);

int main() {
	ios::sync_with_stdio(false);
	int w, n;
	cin >> w >> n;
	vector<int> arr;
	arr.reserve(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x < w)
			arr.push_back(x);
	}
	n = arr.size();
	for (int k = 2; k < n - 1; ++k)
	{
		int j = k - 1;
		for (int i = 0; i < j; ++i)
			weightSumByTwo[arr[i] + arr[j]] = true;
		for (int l = k + 1; l < n; ++l)
		{
			int target = w - arr[k] - arr[l];
			if (target < 2 || target > 400000) continue;
			if (weightSumByTwo[target])
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}
// 280ms, 29208KB

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {}
	int sum(int pos) {
		++pos; 
		int ret = 0;
		while (pos) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}
	void add(int pos) {
		++pos;
		while (pos < tree.size()) {
			++tree[pos];
			pos += (pos & -pos);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> arr(N), tmp(N);
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> arr[i];
		tmp[i] = arr[i];
	}
	sort(tmp.begin(), tmp.end());
	unordered_map<int, int> ord;
	for (int i = 0; i < N; ++i)
		ord[tmp[i]] = i;
	for (int i = 0; i < N; ++i)
		arr[i] = ord[arr[i]];

	FenwickTree ft(N);
	long long ret = 0;
	ft.add(arr[0]);
	for (int i = 1; i < N; ++i)
	{
		ret += i - ft.sum(arr[i]);
		ft.add(arr[i]);
	}
	cout << ret;
}
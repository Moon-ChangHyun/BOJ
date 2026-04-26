// 156ms, 9840KB

#include<iostream>
#include<vector>

using namespace std;

int N;
int idx[1000001];

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
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		idx[x] = i;
	}
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		arr[i] = idx[x];
	}
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
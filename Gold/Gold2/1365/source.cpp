// 8ms, 2288KB

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n, ret = 1;
	int arr[100'001];
	arr[0] = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if(arr[ret - 1] < x)
			arr[ret++] = x;
		else {
			auto iter = lower_bound(arr, arr + ret, x);
			*iter = x;
		}
	}
	cout << n - --ret;
}
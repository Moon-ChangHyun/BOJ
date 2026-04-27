// 244ms, 9840KB

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v1(n), v2(n);
	for (int i = 0; i < n; ++i)
		cin >> v1[i] >> v2[i];
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	int ret = 0, tem = 0, txm = 0;
	int num = 0, p1 = 0, p2 = 0, lastEnter = 0;
	while (p1 < n)
	{
		if (v1[p1] < v2[p2]) {
			lastEnter = p1++;
			++num;
		}
		else if (v1[p1] == v2[p2]) {
			++p1;
			++p2;
		}
		else {
			if (ret < num) {
				ret = num;
				tem = v1[lastEnter];
				txm = v2[p2];
			}
			++p2;
			--num;
		}
	}
	if (ret < num) {
		ret = num;
		tem = v1[lastEnter];
		txm = v2[p2];
	}
	cout << ret << endl << tem << ' ' << txm;
}
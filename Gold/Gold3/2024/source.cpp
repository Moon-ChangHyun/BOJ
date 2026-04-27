// 24ms, 2412KB

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	while (cin >> m)
	{
		m += 50000;
		vector<int> far(100001, -1);
		while (true)
		{
			int l, r;
			cin >> l >> r;
			if (l == 0 && r == 0)
				break;
			l += 50000;
			r += 50000;
			far[l] = max(far[l], r);
		}
		int ret = 0, r = 50000, tmp = -1;
		for (int l = 0; l <= r; ++l)
			tmp = max(tmp, far[l]);
		if (tmp == -1) {
			cout << "0\n";
			continue;
		}
		bool complete = true;
		++ret;
		while (true) {
			int s = r + 1, e = tmp;
			if (m <= (r = tmp))
				break;
			for (int l = s; l <= e; ++l)
				tmp = max(tmp, far[l]);
			if (r == tmp) {
				complete = false;
				break;
			}
			else
				++ret;
		}
		if (complete)
			cout << ret << '\n';
		else
			cout << "0\n";
	}
}
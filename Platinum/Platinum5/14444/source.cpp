// 4ms, 3312KB

#include<iostream>
#include<algorithm>
using namespace std;

int p[200'001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string str;
	cin >> str;

	int n = str.size();
	str.resize((n << 1) + 1);
	for (int i = n; ~--i; ) {
		str[(i << 1) + 1] = str[i];
		str[(i << 1) + 2] = '#';
	}
	str[0] = '#';
	n = str.size();

	int k = 0;
	for (int i = 0; i < n; ++i) {
		int r = k + p[k];
		if (i <= r) p[i] = min(p[2 * k - i], r - i);
		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && str[i - p[i] - 1] == str[i + p[i] + 1]) ++p[i];
		if (r < i + p[i]) k = i;
	}
	
	int result = 0;
	for (int i = 0; i < n; ++i) {
		result = max(result, p[i]);
	}

	cout << result;
}
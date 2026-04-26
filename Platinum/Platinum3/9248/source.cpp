// 600ms, 10476KB

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    string s;
	cin >> s;
	int n = s.size();
	int t = 1;
	vector<int> group(n + 1);
	for (int i = 0; i < n; ++i)
		group[i] = s[i];
	group[n] = -1;
    vector<int> suffixArray(n);
	for (int i = 0; i < n; ++i)
		suffixArray[i] = i;
	auto comp = [&group, &t](int a, int b) {
		if (group[a] != group[b])
			return group[a] < group[b];
		return group[a + t] < group[b + t];
	};
	while (t < n)
	{
		sort(suffixArray.begin(), suffixArray.end(), comp);
		if ((t << 1) >= n) break;
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[suffixArray[0]] = 0;
		for (int i = 1; i < n; ++i)
			newGroup[suffixArray[i]] = newGroup[suffixArray[i - 1]] +
			(comp(suffixArray[i - 1], suffixArray[i]) ? 1 : 0);
		group = move(newGroup);
		t <<= 1;
	}

	vector<int> rank(n + 1);
	for (int i = 0; i < n; ++i) {
		cout << (1 + suffixArray[i]) << ' ';
		rank[suffixArray[i]] = i;
	}
	cout << "\nx ";
	vector<int> lcp(n + 1);
	int len = 0;
	for (int i = 0; i < n; ++i) {
		int r = rank[i];
		if (r) {
			int j = suffixArray[r - 1];
			while (s[i + len] == s[j + len]) ++len;
			lcp[r] = len;
			if (len) --len;
		}
	}
	for (int i = 1; i < n; ++i)
		cout << lcp[i] << ' ';
}
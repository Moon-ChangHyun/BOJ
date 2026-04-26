// 12ms, 2412KB

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class disjointSet {
	vector<int> group;
	int find(int u)
	{
		if (u == group[u]) return u;
		return group[u] = find(group[u]);
	}
public:
	disjointSet(int sz) : group(sz)
	{
		for (int i = 0; i < sz; ++i)
			group[i] = i;
	}
	bool use(int u)
	{
		int fu = find(u);
		if (fu == 0) return false;
		int fv = find(u - 1);
		group[u] = fv;
		if (fu == fv) {
			group[fv] = find(fv - 1);
		}
		return true;
	}
};

int main()
{
    ios::sync_with_stdio(false);
    int G, P, ret = 0;
    cin >> G >> P;
	disjointSet ds(G + 1);
	bool closed = false;
    for (int i = 0; i < P; ++i)
    {
		int x;
		cin >> x;
		if (closed) continue;
		if (!ds.use(x))
			closed = true;
		else
			++ret;
    }
    cout << ret;
}
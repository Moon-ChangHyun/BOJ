// 44ms, 2192KB

#include<iostream>
#include<vector>

using namespace std;

class disjointSet {
	vector<int> group;
	vector<int> size;
	vector<int> rank;
public:
	int groupCnt, largeGroup;
	disjointSet(int sz) : group(sz), size(sz, 1), rank(sz, 0), groupCnt(sz), largeGroup(1)
	{
		for (int i = 0; i < sz; ++i)
			group[i] = i;
	}

	int find(int u)
	{
		if (u == group[u]) return u;
		return group[u] = find(group[u]);
	}

	void merge(int u, int v)
	{
		u = find(u), v = find(v);
		if (u == v) return;
		if (rank[u] < rank[v])
		{
			u ^= v;
			v ^= u;
			u ^= v;
		}
		group[v] = u;
		size[u] += size[v];
		if (rank[u] == rank[v])
			++rank[u];
		--groupCnt;
		largeGroup = max(largeGroup, size[u]);
	}
};

struct line {
	int sX, sY, eX, eY;
};
istream& operator>> (istream& is, line& ln)
{
	return is >> ln.sX >> ln.sY >> ln.eX >> ln.eY;
}
vector<line> lines;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	long long a1 = x2 - x1, a2 = y2 - y1;
	long long b1 = x3 - x1, b2 = y3 - y1;
	long long val = a1 * b2 - a2 * b1;
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

bool func(int idx1, int idx2)
{
	int x1 = lines[idx1].sX, y1 = lines[idx1].sY, x2 = lines[idx1].eX, y2 = lines[idx1].eY, x3 = lines[idx2].sX, y3 = lines[idx2].sY, x4 = lines[idx2].eX, y4 = lines[idx2].eY;
	int ccw123 = ccw(x1, y1, x2, y2, x3, y3);
	int ccw124 = ccw(x1, y1, x2, y2, x4, y4);
	if (ccw123 == 0)
	{
		if (ccw124 == 0)
		{
			if (x1 < x2)
			{
				if (x3 < x4)
					return x3 <= x2 && x1 <= x4;
				return x4 <= x2 && x1 <= x3;
			}
			else if (x1 > x2)
			{
				if (x3 < x4)
					return x3 <= x1 && x2 <= x4;
				return x4 <= x1 && x2 <= x3;
			}
			else
			{
				if (y1 < y2)
				{
					if (y3 < y4)
						return y3 <= y2 && y1 <= y4;
					return y4 <= y2 && y1 <= y3;
				}
				else
				{
					if (y3 < y4)
						return y3 <= y1 && y2 <= y4;
					return y4 <= y1 && y2 <= y3;
				}
			}
		}
		if (x1 < x2)
			return x1 <= x3 && x3 <= x2;
		else if (x1 > x2)
			return x2 <= x3 && x3 <= x1;
		else
		{
			if (y1 < y2)
				return y1 <= y3 && y3 <= y2;
			else
				return y2 <= y3 && y3 <= y1;
		}
	}
	else
	{
		if (ccw124 == 0)
		{
			if (x1 < x2)
				return x1 <= x4 && x4 <= x2;
			else if (x1 > x2)
				return x2 <= x4 && x4 <= x1;
			else
			{
				if (y1 < y2)
					return y1 <= y4 && y4 <= y2;
				else
					return y2 <= y4 && y4 <= y1;
			}
		}
		else
		{
			if (ccw123 * ccw124 == 1) return 0;
			int ccw341 = ccw(x3, y3, x4, y4, x1, y1);
			int ccw342 = ccw(x3, y3, x4, y4, x2, y2);
			return ccw341 * ccw342 <= 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, groupCnt = 0, largeGroup = 0;
	cin >> n;
	lines.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> lines[i];
	disjointSet ds(n);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (func(i, j))
				ds.merge(i, j);
	cout << ds.groupCnt << '\n' << ds.largeGroup;
}
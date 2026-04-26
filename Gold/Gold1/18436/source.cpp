// 72ms, 5548KB

#include<iostream>
#include<vector>

using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b)
{
	return { a.first + b.first, a.second + b.second };
}

struct RangeQuery {
	RangeQuery(const vector<int>& A) : n(A.size()), rangeAO(A.size() * 4)
	{
		init(A, 1, 0, n - 1);
	}
	int getEven(int l, int r)
	{
		return query(l - 1, r - 1, 1, 0, n - 1).first;
	}
	int getOdd(int l, int r)
	{
		return query(l - 1, r - 1, 1, 0, n - 1).second;
	}
	void change(int i, int x)
	{
		change(i - 1, x, 1, 0, n - 1);
	}
private:
	int n;
	vector<pair<int, int>> rangeAO; //<짝,홀>
	pair<int, int> init(const vector<int>& A, int nd, int ndL, int ndR)
	{
		if (ndL == ndR)
		{
			if (A[ndL] & 1)
				return rangeAO[nd] = { 0,1 };
			else
				return rangeAO[nd] = { 1, 0 };
		}
		int mid = (ndL + ndR) >> 1;
		return rangeAO[nd] = init(A, nd << 1, ndL, mid) + init(A, (nd << 1) + 1, mid + 1, ndR);
	}
	pair<int, int> query(int l, int r, int nd, int ndL, int ndR)
	{
		if (r < ndL || ndR < l)
			return { 0, 0 };
		if (l <= ndL && ndR <= r)
			return rangeAO[nd];
		int mid = (ndL + ndR) >> 1;
		return query(l, r, nd << 1, ndL, mid) + query(l, r, (nd << 1) + 1, mid + 1, ndR);
	}
	pair<int, int> change(int i, int x, int nd, int ndL, int ndR)
	{
		if (i < ndL || ndR < i)
			return rangeAO[nd];
		if (ndL == ndR)
		{
			if (x & 1)
				return rangeAO[nd] = { 0, 1 };
			else
				return rangeAO[nd] = { 1, 0 };
		}
		int mid = (ndL + ndR) >> 1;
		return rangeAO[nd] = change(i, x, nd << 1, ndL, mid) + change(i, x, (nd << 1) + 1, mid + 1, ndR);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	RangeQuery rq(A);
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			rq.change(b, c);
		}
		else if (a == 2)
		{
			cout << rq.getEven(b, c) << '\n';
		}
		else
		{
			cout << rq.getOdd(b, c) << '\n';
		}
	}
}
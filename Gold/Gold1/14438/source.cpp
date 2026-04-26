// 64ms, 3980KB

#include<iostream>
#include<vector>

using namespace std;
constexpr int INF = 1987654321;

struct RMQ {
	RMQ(const vector<int>& A) : n(A.size()), rangeMin(A.size() * 4)
	{
		init(A, 0, n - 1, 1);
	}
	int query(int l, int r)
	{
		return query(l - 1, r - 1, 1, 0, n - 1);
	}
	void change(int i, int v)
	{
		change(i - 1, v, 1, 0, n - 1);
	}
private:
	int n;
	vector<int> rangeMin;
	int init(const vector<int>& A, int ndL, int ndR, int nd)
	{
		if (ndL == ndR)
			return rangeMin[nd] = A[ndL];
		int mid = (ndL + ndR) >> 1;
		return rangeMin[nd] = min(init(A, ndL, mid, nd << 1), init(A, mid + 1, ndR, (nd << 1) + 1));
	}
	int query(int l, int r, int nd, int ndL, int ndR)
	{
		if (r < ndL || ndR < l)
			return INF;
		if (l <= ndL && ndR <= r)
			return rangeMin[nd];
		int mid = (ndL + ndR) >> 1;
		return min(query(l, r, nd << 1, ndL, mid), query(l, r, (nd << 1) + 1, mid + 1, ndR));
	}
	int change(int i, int v, int nd, int ndL, int ndR)
	{
		if (i < ndL || ndR < i)
			return rangeMin[nd];
		if (ndL == ndR)
			return rangeMin[nd] = v;
		int mid = (ndL + ndR) >> 1;
		return rangeMin[nd] = min(change(i, v, nd << 1, ndL, mid), change(i, v, (nd << 1) + 1, mid + 1, ndR));
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
	RMQ rmq(A);
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			rmq.change(b, c);
		else
			cout << rmq.query(b, c) << '\n';
	}
}
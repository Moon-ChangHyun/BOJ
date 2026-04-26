// 184ms, 22672KB

#include<iostream>
#include<vector>
#include<complex>
#include<numbers>

using namespace std;
using cpx = complex<double>;

void DFT(vector<cpx>& f, cpx x)
{
	int n = f.size();
	if (n == 1) return;
	int halfN = n >> 1;
	vector<cpx> even(halfN), odd(halfN);
	for (int i = 0; i < n; ++i)
		(i & 1 ? odd : even)[i >> 1] = f[i];
	DFT(even, x * x);
	DFT(odd, x * x);
	cpx w(1, 0);
	for (int i = 0; i < halfN; ++i)
	{
		f[i] = even[i] + w * odd[i];
		f[i + halfN] = even[i] - w * odd[i];
		w *= x;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int N, dN;
	cin >> N;
	dN = N << 1;
	int l = (N << 2) - 1, n = 1;
	while (n <= l) n <<= 1;
	vector<cpx> a(n), b(n), c(n);
	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;
		a[N - 1 - i].real(k);
		a[dN - 1 - i].real(k);
	}
	for (int i = N; i < dN; ++i)
	{
		int k;
		cin >> k;
		b[i].real(k);
	}
	auto theta = 2 * numbers::pi / n;
	cpx x(cos(theta), sin(theta));
	DFT(a, x);
	DFT(b, x);
	for (int i = 0; i < n; ++i)
		c[i] = a[i] * b[i];
	DFT(c, cpx(1, 0) / x);
	for (int i = 0; i < n; ++i)
	{
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}
	long long ret = 0;
	for (int i = dN - 1; i < dN - 1 + N; ++i)
		ret = max(ret, (long long)c[i].real());
	cout << ret;
}
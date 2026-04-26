// 672ms, 85036KB

#include<iostream>
#include<vector>
#include<complex>
#include<cmath>
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

string multiply(const string& numA, const string& numB) 
{
	int la = numA.size(), lb = numB.size();
	int l = la + lb - 1;
	int n = 1;
	while (n <= l)
		n <<= 1;
	vector<cpx> a(n), b(n), c(n);
	for (int i = la; ~--i;)
		a[la - 1 - i].real(numA[i] - '0');
	for (int i = 0; numB[i]; ++i)
		b[lb - 1 - i].real(numB[i] - '0');

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

	string ret;
	
	int carryUp = 0;
	for (int i = 0; i < n; ++i)
	{
		int val = carryUp + c[i].real();
		carryUp = val / 10;
		ret.push_back((val - carryUp * 10) + '0');
	}
	while (carryUp) 
	{
		ret.push_back(carryUp % 10 + '0');
		carryUp /= 10;
	}
	while (ret.size() > 1 && ret.back() == '0') 
		ret.pop_back();
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	string aNum, bNum;
	cin >> aNum >> bNum;
	cout << multiply(aNum, bNum);
}
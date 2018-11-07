#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <regex>
#include <functional>
#include <algorithm>
class bigInt
{
public:
	bigInt();
	bigInt(long long);
	bigInt(const bigInt&);
	bigInt(const bigInt&&);
	virtual ~bigInt();
	bigInt& operator=(const bigInt&);
	bigInt& operator=(const bigInt&&);
	bigInt& operator+=(const bigInt&);
	bigInt& operator-=(const bigInt&);
	bigInt& operator*=(const bigInt&);
	bigInt& operator/=(const bigInt&);
	bigInt& operator%=(const bigInt&);
	bigInt& operator++();
	bigInt& operator--();
	bigInt operator++(int);
	bigInt operator--(int);
	const bigInt operator-() const;
	friend const bigInt operator+(const bigInt&, const bigInt&);
	friend const bigInt operator-(const bigInt&, const bigInt&);
	friend const bigInt operator*(const bigInt&, const bigInt&);
	friend const bigInt operator/(const bigInt&, const bigInt&);
	friend const bigInt operator%(const bigInt&, const bigInt&);
	friend const bool operator==(const bigInt&, const bigInt&);
	friend const bool operator!=(const bigInt&, const bigInt&);
	friend const bool operator<(const bigInt&, const bigInt&);
	friend const bool operator>(const bigInt&, const bigInt&);
	friend const bool operator<=(const bigInt&, const bigInt&);
	friend const bool operator>=(const bigInt&, const bigInt&);
	friend std::ostream& operator<<(std::ostream&, const bigInt&);
	friend std::istream& operator>>(std::istream&, bigInt&);
	const bigInt abs() const;
	std::pair<bigInt, bigInt> divide(const bigInt&) const;
private:
	bool sign;
	std::vector<char> number;
};

bigInt::bigInt() : sign(true)
{
}

bigInt::bigInt(long long initVal) : sign(true)
{
	if (initVal != 0) {
		if (initVal < 0) {
			sign = false;
			initVal = -initVal;
		}
		char remainder;
		while (initVal) {
			remainder = initVal % 10;
			number.push_back(remainder);
			initVal /= 10;
		}
	}
}

bigInt::bigInt(const bigInt & src) : sign(src.sign), number(src.number)
{
}

bigInt::bigInt(const bigInt && src) : sign(src.sign), number(std::move(src.number))
{
}

bigInt::~bigInt()
{
}

bigInt & bigInt::operator=(const bigInt & rhs)
{
	if (this == &rhs) return *this;
	sign = rhs.sign;
	number = rhs.number;
	return *this;
}

bigInt & bigInt::operator=(const bigInt && rhs)
{
	if (this == &rhs) return *this;
	sign = rhs.sign;
	number = std::move(rhs.number);
	return *this;
}

bigInt & bigInt::operator+=(const bigInt & rhs)
{
	return *this = operator+(*this, rhs);
}

bigInt & bigInt::operator-=(const bigInt & rhs)
{
	return *this = operator+(*this, -rhs);
}

bigInt & bigInt::operator*=(const bigInt & rhs)
{
	return *this = operator*(*this, rhs);
}

bigInt & bigInt::operator/=(const bigInt & rhs)
{
	return *this = operator/(*this, rhs);
}

bigInt & bigInt::operator%=(const bigInt & rhs)
{
	return *this = operator%(*this, rhs);
}

bigInt & bigInt::operator++()
{
	return operator+=(1);
}

bigInt & bigInt::operator--()
{
	return operator+=(-1);
}

bigInt bigInt::operator++(int)
{
	bigInt ret(*this);
	operator+=(1);
	return ret;
}

bigInt bigInt::operator--(int)
{
	bigInt ret(*this);
	operator+=(-1);
	return ret;
}

const bigInt bigInt::operator-() const
{
	bigInt ret(*this);
	ret.sign = !ret.sign;
	return ret;
}

const bigInt operator+(const bigInt & lhs, const bigInt & rhs)
{
	bigInt ret;
	if (lhs.abs() < rhs.abs()) return operator+(rhs, lhs);
	int a = 0, b, ind = 0, lE = lhs.number.size(), rE = rhs.number.size();
	if (lhs.sign ^ rhs.sign) {
		ret.sign = lhs.sign;
		for (; ind != lE; ++ind) {
			b = a;
			b += lhs.number[ind];
			if (ind < rE)
				b -= rhs.number[ind];
			if (b < 0) {
				a = -1;
				b += 10;
			}
			else a = 0;
			ret.number.push_back(b);
		}
		if (ret.number.back() == 0) ret.number.pop_back();
	}
	else {
		ret.sign = lhs.sign;
		for (; ind != lE; ++ind) {
			b = a;
			b += lhs.number[ind];
			if (ind < rE)
				b += rhs.number[ind];
			if (b >= 10) {
				a = 1;
				b -= 10;
			}
			else a = 0;
			ret.number.push_back(b);
		}
		if (a) ret.number.push_back(a);
	}
	return ret;
}

const bigInt operator-(const bigInt & lhs, const bigInt & rhs)
{
	return operator+(lhs, -rhs);
}

const bigInt operator*(const bigInt & lhs, const bigInt & rhs)
{
	bigInt ret;
	ret.sign = !(lhs.sign ^ rhs.sign);
	std::function<const std::vector<char>(const std::vector<char>&, const std::vector<char>&)> karatsuba = [&karatsuba](const std::vector<char>& a, const std::vector<char>& b) {
		int an = a.size(), bn = b.size();
		if (an < bn) return karatsuba(b, a);
		if (an == 0 || bn == 0) return std::vector<char>();
		if (an < 50) {
			std::vector<int> c(a.size() + b.size(), 0);
			for (int i = 0; i != a.size(); ++i)
				for (int j = 0; j != b.size(); ++j)
					c[i + j] += a[i] * b[j];
			std::vector<char> ret;
			ret.reserve(c.size());
			int up = 0, val;
			for (int ind = 0; ind != c.size(); ++ind) {
				val = up + c[ind];
				if (val >= 10) {
					up = val / 10;
				}
				else up = 0;
				ret.push_back(val % 10);
			}
			if (ret.back() == 0) ret.pop_back();
			return ret;
		}
		int half = an / 2;
		std::vector<char> a0(a.begin(), a.begin() + half);
		std::vector<char> a1(a.begin() + half, a.end());
		std::vector<char> b0(b.begin(), b.begin() + std::min<int>(b.size(), half));
		std::vector<char> b1(b.begin() + std::min<int>(b.size(), half), b.end());
		std::vector<char> z2 = karatsuba(a1, b1);
		std::vector<char> z0 = karatsuba(a0, b0);
		std::function<void(std::vector<char> &, const std::vector<char> &, int)> addTo = [](std::vector<char> & a, const std::vector<char> & b, int k) {
			std::vector<char> c(k, 0);
			for_each(b.cbegin(), b.cend(), [&c](char num) { c.push_back(num); });
			int up = 0, val;
			while (a.size() < c.size()) a.push_back(0);
			for (int ind = 0; ind != a.size(); ++ind) {
				val = up;
				val += a[ind];
				if (ind < c.size())
					val += c[ind];
				if (val >= 10) {
					up = 1;
					val -= 10;
				}
				else up = 0;
				a[ind] = val;
			}
			if (up) a.push_back(up);
		};
		addTo(a0, a1, 0);
		addTo(b0, b1, 0);
		std::vector<char> z1 = karatsuba(a0, b0);
		std::function<void(std::vector<char> &, const std::vector<char> &)> subFrom = [](std::vector<char> & a, const std::vector<char> & b) {// a>=b
			int up = 0, val;
			for (int ind = 0; ind != a.size(); ++ind) {
				val = up;
				val += a[ind];
				if (ind < b.size())
					val -= b[ind];
				if (val < 0) {
					up = -1;
					val += 10;
				}
				else up = 0;
				a[ind] = val;
			}
		};
		subFrom(z1, z0);
		subFrom(z1, z2);
		std::vector<char> ret;
		addTo(ret, z0, 0);
		addTo(ret, z1, half);
		addTo(ret, z2, half * 2);
		return ret;
	};
	ret.number = karatsuba(lhs.number, rhs.number);
	return ret;
}

const bigInt operator/(const bigInt & lhs, const bigInt & rhs)
{
	return (lhs.divide(rhs)).first;
}

const bigInt operator%(const bigInt & lhs, const bigInt & rhs)
{
	return (lhs.divide(rhs)).second;
}

const bool operator==(const bigInt & lhs, const bigInt & rhs)
{
	int lEnd = lhs.number.size(), rEnd = rhs.number.size();
	if (lhs.sign != rhs.sign || lEnd != rEnd) return false;
	for (int ind = 0; ind != lEnd; ++ind)
		if (lhs.number[ind] != rhs.number[ind]) return false;
	return true;
}

const bool operator!=(const bigInt & lhs, const bigInt & rhs)
{
	return !operator==(lhs, rhs);
}

const bool operator<(const bigInt & lhs, const bigInt & rhs)
{
	if (lhs.sign && !rhs.sign) return false;
	if (!lhs.sign && rhs.sign) return true;
	if (lhs.sign) {
		if (lhs.number.size() < rhs.number.size()) return true;
		if (lhs.number.size() > rhs.number.size()) return false;
		for (int ind = lhs.number.size() - 1, eInd = -1; ind != eInd; --ind)
			if (lhs.number[ind] > rhs.number[ind]) return false;
			else if (lhs.number[ind] < rhs.number[ind]) return true;
		return false;
	}
	else {
		if (lhs.number.size() > rhs.number.size()) return true;
		if (lhs.number.size() < rhs.number.size()) return false;
		for (int ind = lhs.number.size() - 1, eInd = -1; ind != eInd; --ind)
			if (lhs.number[ind] < rhs.number[ind]) return false;
			else if (lhs.number[ind] > rhs.number[ind]) return true;
		return false;
	}
}

const bool operator>(const bigInt & lhs, const bigInt & rhs)
{
	return operator<(rhs, lhs);
}

const bool operator<=(const bigInt & lhs, const bigInt & rhs)
{
	return !operator>(lhs, rhs);
}

const bool operator>=(const bigInt & lhs, const bigInt & rhs)
{
	return !operator<(lhs, rhs);
}

std::ostream & operator<<(std::ostream & out, const bigInt & rhs)
{
	if (rhs.number.size() == 0) {
		out << 0;
		return out;
	}
	if (!rhs.sign) out << '-';
	auto iter = rhs.number.crbegin();
	auto eIter = rhs.number.crend();
	for (; iter != eIter; ++iter) {
		out << (int)*iter;
	}
	return out;
}

std::istream & operator>>(std::istream & in, bigInt & rhs)
{
	std::regex r(R"(^(?:\+|-)?\d+$)");
	std::string s;
	in >> s;
	if (std::regex_match(s, r)) {
		rhs.sign = true;
		rhs.number.clear();
		int eInd = 0, ind = s.size() - 1;
		if (s[eInd] == '-') {
			rhs.sign = false;
			++eInd;
		}
		else if (s[eInd] == '+') {
			++eInd;
		}
		if (s[eInd] == '0') {
			while (s[eInd] == '0') ++eInd;
		}
		--eInd;
		while (ind != eInd)
			rhs.number.push_back(s[ind--] - '0');
	}
	return in;
}

const bigInt bigInt::abs() const
{
	bigInt ret(*this);
	ret.sign = true;
	return ret;
}

std::pair<bigInt, bigInt> bigInt::divide(const bigInt & rhs) const
{
	return std::pair<bigInt, bigInt>();
}

using namespace std;
array<array<bigInt, 101>, 101> c;
bigInt combination(int n, int m) {
	if (n < m) return 0;
	if (m == 0) return 1;
	bigInt& ret = c[n][m];
	if (ret > 0) return ret;
	return ret = combination(n - 1, m) + combination(n - 1, m - 1);
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	cout << combination(a, b);
}
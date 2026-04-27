// 728ms, 5516KB

#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

constexpr int buffSize = 2000001;
bool isNotPrime[buffSize];
vector<int> primeNums;

void preProcessing() {
	isNotPrime[0] = isNotPrime[1] = true;
	for (ll i = 2; i < buffSize; ++i) {
		if (isNotPrime[i])
			continue;
		primeNums.push_back(i);
		for (ll j = i * i; j < buffSize; j += i)
			isNotPrime[j] = true;
	}
}

bool primeTest(ll num) {
	if (num < buffSize)
		return !isNotPrime[num];
	for (auto p : primeNums) {
		if (num % p == 0)
			return false;
	}
	return true;
}

bool isCoupleNumber(ll sum) {
	if (sum & 1)
		return primeTest(sum - 2);
	return sum > 2; //골드바흐의 추측
}

int main() {
	preProcessing();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	for (cin >> T; ~--T; ) {
		ll A, B;
		cin >> A >> B;
		cout << (isCoupleNumber(A + B) ? "YES\n" : "NO\n");
	}
}
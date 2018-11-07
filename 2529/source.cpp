#include<vector>
#include<cstdio>
using namespace std;

bool ret = false;
int k, visit;
vector<char> str, num;

void getMxNum(int idx) {
	if (idx > k) {
		ret = true;
		return;
	}
	int digit, lower;
	if (idx == 0 || str[idx - 1] == '<') {
		digit = 10;
		lower = idx ? (num[idx - 1] & 0xf) : -1;
	}
	else {
		digit = num[idx - 1] & 0xf;
		lower = -1;
	}
	for (; --digit != lower;) {
		if (!(visit & (1 << digit))) {
			visit |= (1 << digit);
			num[idx] = '0' + digit;
			getMxNum(idx + 1);
			visit &= ~(1 << digit);
			if (ret) break;
		}
	}
}

void getMnNum(int idx) {
	if (idx > k) {
		ret = true;
		return;
	}
	int digit, upper;
	if (idx == 0 || str[idx - 1] == '>') {
		digit = -1;
		upper = idx ? (num[idx - 1] & 0xf) : 10;
	}
	else {
		digit = num[idx - 1] & 0xf;
		upper = 10;
	}
	for (; ++digit != upper;) {
		if (!(visit & (1 << digit))) {
			visit |= (1 << digit);
			num[idx] = '0' + digit;
			getMnNum(idx + 1);
			visit &= ~(1 << digit);
			if (ret) break;
		}
	}
}

int main() {
	scanf("%d", &k);
	str.resize(k);
	num.resize(k + 1);
	for (int i = 0; i != k; ++i)
		scanf(" %c", &str[i]);
	getMxNum(0);
	for (int i = 0; i <= k; ++i)
		putchar(num[i]);
	putchar('\n');
	ret = false;
	visit = 0;
	getMnNum(0);
	for (int i = 0; i <= k; ++i)
		putchar(num[i]);
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct Serial {
	string data;
	int sum;
	Serial() : sum(0) {
		char str[51];
		scanf("%s", str);
		data = move(string(str));
		for (auto& iter : data)
			if (iter <= '9')
				sum += iter - '0';
	}
	const bool operator<(const Serial& rhs) {
		if (data.size() != rhs.data.size()) return data.size() < rhs.data.size();
		if (sum != rhs.sum) return sum < rhs.sum;
		return data < rhs.data;
	}
	void print() {
		cout << data << endl;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	int N;
	scanf("%d", &N);
	getchar();
	vector<Serial> v(N);
	sort(v.begin(), v.end());
	for (auto& iter : v)
		iter.print();
}
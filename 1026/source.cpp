#include<iostream>
#include<set>
#include<functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	multiset<int> A;
	multiset<int, greater<>> B;
	int temp;
	for (int i = 0; i != N; ++i) {
		cin >> temp;
		A.insert(temp);
	}
	for (int i = 0; i != N; ++i) {
		cin >> temp;
		B.insert(temp);
	}
	temp = 0;
	multiset<int>::const_iterator aIter = A.cbegin();
	multiset<int, greater<>>::const_iterator bIter = B.cbegin();
	for (int i = 0; i != N; ++i)
		temp += (*(aIter++)) * (*(bIter++));
	cout << temp;
	return 0;
}
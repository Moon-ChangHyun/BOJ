#include<cstdio>
#include<array>
using namespace std;
int main() {
	int s = 0, t;
	array<int, 100> arr;
	arr.fill(0);
	for (int i = 0; i != 10; ++i) {
		scanf("%d", &t);
		t /= 10;
		s += t;
		++arr[t];
	}
	t = 0;
	for (int i = 1; i != 100; ++i)
		t = arr[i] > arr[t] ? i : t;
	printf("%d\n%d", s, t * 10);
}
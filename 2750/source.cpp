#include<cstdio>
using namespace std;
int n, k, x, arr[1000];
void f(int begin, int end) {
	if (end - begin <= 1) return;
	int tmp;
	int pivot = end - 1;
	int lp = begin;
	int rp = end - 2;
	while (true) {
		while (arr[lp] <= arr[pivot] && lp != pivot) ++lp;
		while (arr[rp] >= arr[pivot] && rp != begin) --rp;
		if (rp - lp <= 0) {
			tmp = arr[pivot];
			arr[pivot] = arr[lp];
			arr[lp] = tmp;
			break;
		}
		tmp = arr[lp];
		arr[lp] = arr[rp];
		arr[rp] = tmp;
	}
	f(begin, ++rp);
	f(++lp, end);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i != n; ++i)
		scanf("%d", arr + i);
	f(0, n);
	for (int i = 0; i != n; ++i)
		printf("%d\n", arr[i]);
}
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int arr[3];
	for (int i = 0; i != 3; ++i) scanf("%d", arr + i);
	sort(arr, arr + 3);
	int a = arr[1] - arr[0], b = arr[2] - arr[1];
	if (a == b * 2) printf("%d", arr[0] + b);
	else if (a == b) printf("%d", arr[0] - a);
	else printf("%d", arr[1] + a);
}
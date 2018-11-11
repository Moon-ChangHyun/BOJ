#include<array>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	array<int, 3> arr;
	for (int i = 0; i != 3; ++i) scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	for (auto iter : arr) printf("%d ", iter);
}
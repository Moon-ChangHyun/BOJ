#include<cstdio>
#include<array>
#include<algorithm>
using namespace std;
int main() {
	array<int, 4> arr;
	for (int i = 0; i != 4; ++i) scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	printf("%d", arr[2] * arr[0]);
}
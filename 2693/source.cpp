#include<cstdio>
#include<array>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
	int T;
	for (scanf("%d", &T); ~--T;) {
		array<int, 10> arr;
		for (auto& iter : arr) scanf("%d", &iter);
		nth_element(arr.begin(), arr.begin() + 2, arr.end(), greater<>());
		printf("%d\n", arr[2]);
	}
}
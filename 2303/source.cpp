#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int N, ret = 0, highScore = 0;
	scanf("%d", &N);
	for (int man = 1; man <= N; ++man) {
		int arr[5], sum = 0;
		for (int i = 0; i != 5; ++i) {
			scanf("%d", arr + i);
			sum += arr[i];
		}
		int num = 0;
		for (int a = 0; a < 4; ++a)
			for (int b = a + 1; b < 5; ++b)
				num = max(num, (sum - arr[a] - arr[b]) % 10);
		if (num >= highScore) {
			highScore = num;
			ret = man;
		}
	}
	printf("%d", ret);
}
#include<cstdio>
int arr[10];
int main() {
	int sum = 0, ret, i;
	for (i = 0; i != 10; ++i) {
		scanf("%d", arr + i);
		sum += arr[i];
		if (sum > 100) {
			if (sum - 100 > 100 - sum + arr[i])
				ret = sum - arr[i];
			else
				ret = sum;
			break;
		}

	}
	if (i == 10)
		ret = sum;
	printf("%d", ret);
}
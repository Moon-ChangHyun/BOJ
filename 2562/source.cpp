#include<cstdio>
int main() {
	int arr[9], max = 0;
	for (int i = 0; i != 9; ++i) {
		scanf("%d", arr + i);
		if (arr[max] < arr[i]) max = i;
	}
	printf("%d\n%d", arr[max], max + 1);
}
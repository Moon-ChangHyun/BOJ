#include<cstdio>
int nums[10];
int main() {
	char c;
	while (~scanf("%c", &c))
		++nums[c - '0'];
	for (int i = 9; i >= 0; --i)
		while (nums[i] > 0) {
			printf("%d", i);
			--nums[i];
		}
}
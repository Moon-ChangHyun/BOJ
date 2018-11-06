#include<cstdio>
#include<array>
int main() {
	int a, b, d = 1;
	scanf("%d%d", &a, &b);
	std::array<int, 1001> v{ 0 };
	for (int i = 1; i <= b;) {
		for (int j = 0; i <= b && j != d; ++j, ++i)
			v[i] = v[i - 1] + d;
		++d;
	}
	printf("%d", v[b] - v[a - 1]);
}
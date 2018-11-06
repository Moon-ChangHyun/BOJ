#include <iostream>
int main() {
	int n;
	scanf("%d", &n);
	int head = 0, tail = 0;
	int tmp;
	int cards[1000];
	for (int i = 0; i != n; ++i)
		cards[i] = i + 1;
	while (true) {
		printf("%d ", cards[head]);
		head = (head + 1) % n;
		cards[tail] = cards[head];
		head = (head + 1) % n;
		tail = (tail + 1) % n;
		if (head == tail)
			break;
	}
}
#include<cstdio>
#include<array>
#include<algorithm>
using namespace std;
int main() {
	int score = 0;
	char color[5];
	int num[5];
	for (int i = 0; i != 5; ++i)
		scanf(" %c%d", color + i, num + i);
	sort(color, color + 5);
	sort(num, num + 5);
	bool sameColor = (color[0] == color[4]);
	if (sameColor && num[0] + 4 == num[4]) // rule 1
		score = num[4] + 900;
	else if (num[0] == num[3] || num[1] == num[4]) // rule 2
		score = num[1] + 800;
	else if (num[0] == num[2] && num[3] == num[4]) // rule 3
		score = num[0] * 10 + num[3] + 700;
	else if (num[0] == num[1] && num[2] == num[4]) // rule 3
		score = num[2] * 10 + num[0] + 700;
	else if (sameColor) // rule 4
		score = num[4] + 600;
	else if (num[0] + 1 == num[1] && num[1] + 1 == num[2] && num[2] + 1 == num[3] && num[3] + 1 == num[4]) // rule 5
		score = num[4] + 500;
	else if (num[0] == num[2] || num[2] == num[4]) // rule 6
		score = num[2] + 400;
	else if ((num[0] == num[1] && (num[2] == num[3] || num[3] == num[4])) || (num[1] == num[2] && num[3] == num[4])) // rule 7
		score = max(num[1], num[3]) * 10 + min(num[1], num[3]) + 300;
	else if (num[0] == num[1] || num[1] == num[2]) // rule 8
		score = num[1] + 200;
	else if (num[2] == num[3] || num[3] == num[4]) // rule 8
		score = num[3] + 200;
	else
		score = num[4] + 100;
	printf("%d", score);
}
#include<cstdio>
int team1Win, team2Win, team1Goal, team2Goal, tp, n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		int a, mm, ss;
		char c;
		scanf("%d%2d%c%2d", &a, &mm, &c, &ss);
		if (a == 1) {
			++team1Goal;
			if (team1Goal == team2Goal) {
				team2Win += mm * 60 + ss - tp;
			}
			else if (team1Goal == team2Goal + 1) {
				tp = mm * 60 + ss;
			}
		}
		else {
			++team2Goal;
			if (team1Goal == team2Goal) {
				team1Win += mm * 60 + ss - tp;
			}
			else if (team2Goal == team1Goal + 1) {
				tp = mm * 60 + ss;
			}
		}
	}
	if (team1Goal > team2Goal) {
		team1Win += 2880 - tp;
	}
	else if (team2Goal > team1Goal) {
		team2Win += 2880 - tp;
	}
	printf("%02d:%02d\n", team1Win / 60, team1Win % 60);
	printf("%02d:%02d\n", team2Win / 60, team2Win % 60);
}
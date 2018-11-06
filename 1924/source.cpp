#include <iostream>
int main() {
	int x, y, d = -1;
	std::cin >> x >> y;
	switch (x) {
	case 12:
		d += 30;
	case 11:
		d += 31;
	case 10:
		d += 30;
	case 9:
		d += 31;
	case 8:
		d += 31;
	case 7:
		d += 30;
	case 6:
		d += 31;
	case 5:
		d += 30;
	case 4:
		d += 31;
	case 3:
		d += 28;
	case 2:
		d += 31;
	}
	d += y;
	switch (d % 7) {
	case 0:
		printf("MON");
		break;
	case 1:
		printf("TUE");
		break;
	case 2:
		printf("WED");
		break;
	case 3:
		printf("THU");
		break;
	case 4:
		printf("FRI");
		break;
	case 5:
		printf("SAT");
		break;
	case 6:
		printf("SUN");
	}
}
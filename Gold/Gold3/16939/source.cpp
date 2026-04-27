// 0ms, 1116KB

#include <cstdio>
int main() {
	int arr[24];
	for(int i = 0; i != 24; ++i)
		scanf("%d", arr + i);
	if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]) {
		if(arr[8] == arr[9] && arr[9] == arr[10] && arr[10] == arr[11]) {
			if(arr[12] == arr[13] && arr[4] == arr[5] && arr[16] == arr[17] && arr[20] == arr[21] && arr[14] == arr[15] && arr[6] == arr[7] && arr[18] && arr[19] && arr[22] == arr[23]) {
				if(arr[12] == arr[6]) {
					if(arr[5] == arr[18] && arr[16] == arr[22] && arr[20] == arr[14])
						putchar('1');
					else
						putchar('0');
				}
				else if(arr[12] == arr[22]) {
					if(arr[4] == arr[14] && arr[16] == arr[6] && arr[20] == arr[18])
						putchar('1');
					else
						putchar('0');
				}
				else {
					putchar('0');
				}
			}
			else {
				putchar('0');
			}
		}
		else {
			putchar('0');
		}
	}
	else if(arr[12] == arr[13] && arr[13] == arr[14] && arr[14] == arr[15]) {
		if(arr[16] == arr[17] && arr[17] == arr[18] && arr[18] == arr[19]) {
			if(arr[0] == arr[2] && arr[4] == arr[6] && arr[8] == arr[10] && arr[23] == arr[21] && arr[1] == arr[3] && arr[5] == arr[7] && arr[9] && arr[11] && arr[22] == arr[20]) {
				if(arr[0] == arr[5]) {
					if(arr[4] == arr[9] && arr[8] == arr[22] && arr[23] == arr[1])
						putchar('1');
					else
						putchar('0');
				}
				else if(arr[0] == arr[22]) {
					if(arr[4] == arr[1] && arr[8] == arr[5] && arr[23] == arr[9])
						putchar('1');
					else
						putchar('0');
				}
				else {
					putchar('0');
				}
			}
			else {
				putchar('0');
			}
		}
		else {
			putchar('0');
		}
	}
	else if(arr[4] == arr[5] && arr[5] == arr[6] && arr[6] == arr[7]) {
		if(arr[20] == arr[21] && arr[21] == arr[22] && arr[22] == arr[23]) {
			if(arr[2] == arr[3] && arr[16] == arr[18] && arr[9] == arr[8] && arr[15] == arr[13] && arr[0] == arr[1] && arr[17] == arr[19] && arr[11] && arr[10] && arr[14] == arr[12]) {
				if(arr[2] == arr[17]) {
					if(arr[16] == arr[11] && arr[9] == arr[14] && arr[15] == arr[0])
						putchar('1');
					else
						putchar('0');
				}
				else if(arr[2] == arr[14]) {
					if(arr[15] == arr[11] && arr[9] == arr[17] && arr[16] == arr[0])
						putchar('1');
					else
						putchar('0');
				}
				else {
					putchar('0');
				}
			}
			else {
				putchar('0');
			}
		}
		else {
			putchar('0');
		}
	}
	else {
		putchar('0');
	}
}
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	char str[21];
	scanf("%s", str);
	int sum = 0;
	bool isPrime = true;
	for (int i = 0; str[i]; ++i)
		if ('a' <= str[i])
			sum += (str[i] - 'a' + 1);
		else
			sum += (str[i] - 'A' + 27);
	int last = sqrt(sum);
	for (int i = 2; i <= last; ++i)
		if (sum % i == 0)
			isPrime = false;
	printf("%s", isPrime ? "It is a prime word." : "It is not a prime word.");
}
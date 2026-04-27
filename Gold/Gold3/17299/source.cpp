// 280ms, 17644KB

#include<iostream>

using namespace std;

int stack[1000000], A[1000001], F[1000001], NGF[1000001];

int main()
{
	ios::sync_with_stdio(false);
	int N, top = -1;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
		++F[A[i]];
		NGF[i] = -1;
	}
	for (int i = 1; i <= N; ++i)
	{
		while (top >= 0 && F[A[stack[top]]] < F[A[i]])
			NGF[stack[top--]] = A[i];
		stack[++top] = i;
	}
	for (int i = 1; i <= N; ++i)
		cout << NGF[i] << ' ';
}
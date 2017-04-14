#include <iostream>
using namespace std;
int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int main()
{
	int count;
	cin >> count;

	int mass[10001];
	int sum[10001];

	mass[0] = 0;
	for (int i = 1; i <= count; i++)
		cin >> mass[i];

	sum[0] = 0;
	sum[1] = mass[1];
	sum[2] = mass[1] + mass[2];

	for (int i = 3; i <= count; i++)
	{
		sum[i] = max((sum[i - 3] + mass[i - 1] + mass[i]), (sum[i - 2] + mass[i]));
		sum[i] = max(sum[i - 1], sum[i]);
	}
		cout << sum[count];
}
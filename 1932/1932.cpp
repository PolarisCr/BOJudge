#include <iostream>
using namespace std;
int arr[501][501] = { 0 };
int maxarr[501][501] = { 0 };
int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
int main()
{
	int x;
	cin >> x;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= x; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 1)
				maxarr[i][j] = maxarr[i - 1][1] + arr[i][j];

			else if (j == i)
				maxarr[i][j] = maxarr[i - 1][j - 1] + arr[i][j];

			else
			{
				maxarr[i][j] = max(maxarr[i - 1][j - 1], maxarr[i - 1][j]) + arr[i][j];
			}
		}
	}

	int maxval = -10000;
	for (int i = 1; i <= x; i++)
	{
		if (maxval < maxarr[x][i])
			maxval = maxarr[x][i];
	}
	cout << maxval << endl;
	return 0;
}
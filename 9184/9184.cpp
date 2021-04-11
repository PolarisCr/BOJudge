/*********************************************************
*   Number : Backjoon Online Judge 9184
*   Link : https://www.acmicpc.net/problem/9184
*   Subject : 신나는 함수 실행
*   Status : Pass
*   Submit Number : 28260748
*   Runtime Memory / Time : 2052 KB / 508ms
*   Author : PolarisCr
*********************************************************/
#include <iostream>

using namespace std;

int arr[21][21][21] = { 0, };

int w(int a, int b, int c);

int main()
{
	int a, b, c;

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			arr[i][j][0] = 1;
			arr[i][0][j] = 1;
			arr[0][i][j] = 1;
		}
	}

	while (1)
	{
		cin >> a >> b >> c;

		if ((a == -1) && (b == -1) && (c == -1))
		{
			break;
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}
	return 0;

}

int w(int a, int b, int c)
{
	if ((a <= 0) || (b <= 0) || (c <= 0))
	{
		return arr[0][0][0];
	}

	else if ((a > 20) || (b > 20) || (c > 20))
	{
		return w(20, 20, 20);
	}

	else if ((a < b) && (b < c))
	{
		if (arr[a][b][c] == 0)
		{
			arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
			return arr[a][b][c];
		}
		else
		{
			return arr[a][b][c];
		}
	}
	else
	{
		if (arr[a][b][c] == 0)
		{
			arr[a][b][c] = w(a-1, b, c) + w(a-1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
			return arr[a][b][c];
		}
		else
		{
			return arr[a][b][c];
		}
	}
}

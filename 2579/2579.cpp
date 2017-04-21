#include <iostream>
using namespace std;
int arr[301] = { 0 };
int score[301] = { 0 };

int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}
int main()
{
	int stair;
	cin >> stair;
	for (int i = 1; i <= stair; i++)
	{
		cin >> arr[i];
	}
	score[0] = 0;
	score[1] = arr[1];
	score[2] = arr[1] + arr[2];
	for (int i = 3; i <= stair; i++)
	{
		score[i] = max(score[i - 2], (score[i - 3] + arr[i - 1])) + arr[i];
	}

	cout << score[stair] << endl;

	return 0;
}
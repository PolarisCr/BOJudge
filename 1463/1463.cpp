#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_INT 210000000;
int arr[100001] = { 0 };
int calc(int n)
{
	int temp1 = MAX_INT;
	int temp2 = MAX_INT;
	int temp3 = MAX_INT;

	if ((n % 3) == 0)
	{
		temp1 = arr[n / 3] + 1;

	}
	if ((n % 2) == 0)
	{
		temp2 = arr[n / 2] + 1;
	}
	
	temp3 = arr[n - 1] + 1;

	return min(min(temp1, temp2), temp3);


}
int main()
{
	int test_case;
	cin >> test_case;
	for (int i = 2; i <= test_case; i++)
	{
		arr[i] = calc(i);
	}

	cout << arr[test_case] << endl;
	return 0;
}
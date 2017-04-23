#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> vec;
long long arr[10001] = { 0 };

int main()
{
	int coin, maxcost;
	cin >> coin >> maxcost;

	for (int i = 0; i < coin; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < vec.at(0); i++)
		arr[i] = 0;

	arr[vec[0]] = 1;

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = vec[i]; j <= maxcost; j++)
		{
			arr[j] += arr[j - vec[i]];
		}
	}

	cout << arr[maxcost] << endl;
	return 0;
}
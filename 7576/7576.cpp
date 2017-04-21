#include <iostream>
#include <queue>
using namespace std;
int arr[1002][1002] = { 0 };
queue <pair <int, int> > qu;

int main()
{
	int x, y;
	cin >> x >> y;
	int ripenT = 0;
	int empty = 0;
	for (int i = 1; i <= y; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				qu.push(make_pair(i, j));
				ripenT++;
			}
			if (arr[i][j] == -1)
				empty++;
			
		}

	}

	int size = qu.size();
	int count = 0;
	
	if (ripenT == ((x * y) - empty))
	{
		size = 0;
	}

	while (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			pair <int, int> pos = qu.front();
			qu.pop();
			if ((arr[pos.first + 1][pos.second] == 0) && (pos.first < y))
			{
				arr[pos.first + 1][pos.second] = 1;
				qu.push(make_pair(pos.first + 1, pos.second));
				ripenT++;
			}
			if ((arr[pos.first - 1][pos.second] == 0) && (pos.first > 1))
			{
				arr[pos.first - 1][pos.second] = 1;
				qu.push(make_pair(pos.first - 1, pos.second));
				ripenT++;
			}
			if ((arr[pos.first][pos.second + 1] == 0) && (pos.second < x))
			{
				arr[pos.first][pos.second + 1] = 1;
				qu.push(make_pair(pos.first, pos.second + 1));
				ripenT++;
			}
			if ((arr[pos.first][pos.second - 1] == 0) && (pos.second > 1))
			{
				arr[pos.first][pos.second - 1] = 1;
				qu.push(make_pair(pos.first, pos.second - 1));
				ripenT++;
			}
		}
		size = qu.size();
		count++;
	}
	
	if (ripenT != ((x * y) - empty))
		count = -1;
	else if (count != 0)
		count--;



	cout << count << endl;
	return 0;
}
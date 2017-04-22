#include <iostream>
using namespace std;

long long workspace[101][10] = { 0 };

int main()
{
	int test_case;
	cin >> test_case;

	for (int i = 1; i < 10; i++)
	{
		workspace[0][i] = 0;
		workspace[1][i] = 1;
	}

	for (int i = 2; i <= test_case; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				workspace[i][1] += workspace[i - 1][0];
			}
			else if (j == 9)
			{
				workspace[i][8] += workspace[i - 1][9];
			}
			else
			{
				workspace[i][j - 1] += workspace[i - 1][j];
				workspace[i][j + 1] += workspace[i - 1][j];
			}
			workspace[i][j] %= 1000000000;
		}
	}

	long long result = ((workspace[test_case][0] + workspace[test_case][1]
		+ workspace[test_case][2] + workspace[test_case][3]
		+ workspace[test_case][4] + workspace[test_case][5]
		+ workspace[test_case][6] + workspace[test_case][7]
		+ workspace[test_case][8] + workspace[test_case][9]) % 1000000000);
	cout << result << endl;

	return 0;
}
// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
//#include <map>
#include <iostream>
#include <queue>
#include <functional>
#define max(a,b) a > b ? a : b
using namespace std;

int map[1001][1001] = { 0 };
int value_map_R[1001][1001] = { 0 };
int value_map_L[1001][1001] = { 0 };
int max_value[1001][1001] = { 0 };

int main()
{
	int N, M;
	cin >> N >> M;

	

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= M; i++) // 첫째 줄
	{
		max_value[1][i] = max_value[1][i - 1] + map[1][i];
	}


	for (int i = 2; i <= N; i++)
	{
		// 끝부분
		value_map_R[i][1] = max_value[i - 1][1] + map[i][1];
		value_map_L[i][M] = max_value[i - 1][M] + map[i][M];

		for (int j = 2; j <= M; j++)
		{
			value_map_R[i][j] = max(max_value[i - 1][j], value_map_R[i][j - 1]);
			value_map_R[i][j] = value_map_R[i][j] + map[i][j];
		}

		for (int j = M - 1; j >= 1; j--)
		{
			value_map_L[i][j] = max(max_value[i - 1][j], value_map_L[i][j + 1]);
			value_map_L[i][j] = value_map_L[i][j] + map[i][j];
		}
			
		for (int j = 1; j <= M; j++)
		{
			max_value[i][j] = max(value_map_R[i][j], value_map_L[i][j]);
		}
	}

	cout << max_value[N][M] << endl;

	


    return 0;
}


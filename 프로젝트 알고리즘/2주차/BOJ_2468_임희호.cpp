// BOJ_2468
// 2340KB, 24ms
/*
재난방재청에서는 많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다. 먼저 어떤 지역의 높이 정보를 파악한다.
그 다음에 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 지는 지를 조사하려고 한다.
이때, 문제를 간단하게 하기 위하여, 장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정한다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int** map;
bool** meta_map;
bool** check;
int MAX = 1;
int max_height = 0;

int deltaX[4] = { 0,-1,0,1 };
int deltaY[4] = { -1,0,1,0 };

// 깊이 우선 탐색
void DFS(int y, int x)
{
	check[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + deltaY[i];
		int nextX = x + deltaX[i];

		// 맵을 벗어나면 다른 방향으로
		if (nextY >= N || nextY < 0 || nextX >= N || nextX < 0)
			continue;
		// 이미 방문한 곳이면 다른 방향으로
		if (check[nextY][nextX] == true)
			continue;
		// 물에 잠긴 곳이라면 다른 방향으로
		if (meta_map[nextY][nextX] == true)
			continue;

		DFS(nextY, nextX);
	}
}

void init()
{
	map = new int* [N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
	}
	meta_map = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		meta_map[i] = new bool[N];
	}
	check = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		check[i] = new bool[N];
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에는 어떤 지역을 나타내는 2차원 배열의 행과 열의 개수를 나타내는 수 N이 입력된다. N은 2 이상 100 이하의 정수이다.
	cin >> N;
	init();

	// 둘째 줄부터 N개의 각 줄에는 2차원 배열의 첫 번째 행부터 N번째 행까지 순서대로 한 행씩 높이 정보가 입력된다.
	// 각 줄에는 각 행의 첫 번째 열부터 N번째 열까지 N개의 높이 정보를 나타내는 자연수가 빈 칸을 사이에 두고 입력된다.
	// 높이는 1이상 100 이하의 정수이다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			max_height = max(max_height, map[i][j]);
		}
	}

	// 비의 양에 따른 모든 경우를 다 조사(1부터 시작하면 틀림)
	for (int height = 0; height <= max_height; height++)
	{
		// 높이(height)에 따라 잠기는 부분 체크
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// 비의 양보다 높이가 낮거나 같으면 침수(true), 크면 잠기지 않음(false)
				if (map[i][j] <= height)
					meta_map[i][j] = true;
				else
					meta_map[i][j] = false;

				// 방문기록 초기화
				check[i][j] = false;
			}
		}
		
		// 잠기지 않은 칸에서 DFS
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (meta_map[i][j] == true)
					continue;
				
				if (check[i][j] == true)
					continue;

				DFS(i, j);
				count++;
			}
		}

		MAX = max(MAX, count);
	}
	
	cout << MAX;

	return 0;
}
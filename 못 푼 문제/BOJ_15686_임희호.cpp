#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N , M;

// 위치 저장
typedef struct pos
{
	int x;
	int y;
}Pos;

int distance(Pos pos1, Pos pos2)
{
	return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}

int main()
{
	// 첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.
	cin >> N >> M;

	// 맵 생성
	int **map = new int*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
	}

	// 둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.
	// 도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 
	// 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	// 집 위치와 치킨위치 파악하기
	Pos* pos_home = new Pos[2 * N - 1]{ 0, };
	Pos pos_Chicken[12] = { 0, };
	int home_count = 0, chicken_count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
			{
				pos_home[home_count].x = i;
				pos_home[home_count].y = j;
				home_count++;
				continue;
			}

			if (map[i][j] == 2)
			{
				pos_Chicken[chicken_count].x = i;
				pos_Chicken[chicken_count].y = j;
				chicken_count++;
				continue;
			}
		}
	}

	// 폐업시키지 않을 치킨집 M개를 고르고 난후, 그 때의 치킨거리를 구하고
	// 그중 최소값을 구한다.
	// 치킨집을 기준으로 각 집에대한 거리를 가지기로 하자
	vector<vector<int>> from;
	vector<int> to;
	for (int i = 0; i < chicken_count; i++)
	{
		from.push_back(to);
		for (int j = 0; j < home_count; j++)
		{
			from[i].push_back(distance(pos_Chicken[i], pos_home[j]));
		}
	}

	// M개의 치킨집만 영업할 때 최소값을 가지는 치킨거리를 출력하라.
	for (int i = 0; i < chicken_count; i++)
	{
		from[i]
	}


}
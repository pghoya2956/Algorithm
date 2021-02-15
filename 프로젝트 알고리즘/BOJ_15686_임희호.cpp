#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
// 각 치킨집에서 집까지의 거리를 저장한다. 
int from[13][100] = { 0, };
// 치킨집을 선택했는지 판별한다.
bool chicken_select[13] = { false, };
// 치킨집과 집의 개수
int home_count = 0, chicken_count = 0;

int map[50][50] = { 0, };

int answer = 9999;

// 위치 저장
typedef struct pos
{
	int y;
	int x;
}Pos;

// 거리 계산
int distance(Pos pos1, Pos pos2)
{
	return abs(pos1.y - pos2.y) + abs(pos1.x - pos2.x);
}

// 치킨집이 골라진 상황일 때 계산
int CalculateDistance()
{
	/* cicken_count = 5, M = 3 일 때
	o [ ] [ ] [ ] [ ] [ ]
	o [ ] [ ] [ ] [ ] [ ]
	  [ ] [ ] [ ] [ ] [ ]
	o [ ] [ ] [ ] [ ] [ ]
	  [ ] [ ] [ ] [ ] [ ] */
	// FindChickenDistance함수에서 선택한 M개의 치킨집에서 집까지의 거리중
	// 각 집에 가장 가까운 거리를 선택해서 더한다. -> 선택 상황에서의 치킨거리계산

	int sum = 0;
	for (int i = 0; i < home_count; i++)
	{
		int result = 9999;
		for (int j = 0; j < chicken_count; j++)
		{
			if (chicken_select[j] == true)
				result = min(result, from[j][i]);
		}
		sum += result;
	}

	return sum;
}

void FindChickenDistance(int chicken_index, int count)
{
	// M개의 집을 선택하면 실행
	if (count == M)
	{
		// 각각의 경우에 대한 치킨 거리중 가장 작은 값을 구한다.
		answer = min(answer, CalculateDistance());
		return;
	}

	// 시작인덱스부터 치킨집 개수까지
	for (int i = chicken_index; i < chicken_count; i++)
	{
		// 
		if (chicken_select[i] == true)
			continue;

		// 치킨집을 선택하고 다음 집을 선택한다.
		chicken_select[i] = true;
		FindChickenDistance(i, count + 1);
		chicken_select[i] = false;
	}
}

void input()
{
	// 첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.
	cin >> N >> M;

	// 맵 생성
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
}

void process()
{
	// 집 위치와 치킨위치 파악하기
	Pos pos_home[100] = { 0, };
	Pos pos_Chicken[13] = { 0, };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
			{
				pos_home[home_count] = { i,j };
				home_count++;
				continue;
			}

			if (map[i][j] == 2)
			{
				pos_Chicken[chicken_count] = { i,j };
				chicken_count++;
				continue;
			}
		}
	}

	// 치킨집을 기준으로 각 집에대한 거리를 가지기로 하자
	for (int i = 0; i < chicken_count; i++)
	{
		for (int j = 0; j < home_count; j++)
		{
			from[i][j] = distance(pos_Chicken[i], pos_home[j]);
		}
	}
}

int main()
{
	// 입력
	input();
	// 위치파악, 거리계산
	process();
	// 계산한 거리를 이용해서 모든 경우의 수 탐색
	FindChickenDistance(0, 0);

	// M개의 치킨집을 골랐을 때 치킨거리를 구한다.
	cout << answer << endl;
}

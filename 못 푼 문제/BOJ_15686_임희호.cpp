#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int totalChicken_distance = 0;
int Chicken_distance[100];
int from[13][100] = { 0, };
int home_count = 0, chicken_count = 0;

int result = 9999;

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

int ChickenDistance(int home_count, int chicken_count)
{
	// 치킨집이 다 영업할때 최소값을 가지는 치킨거리를 출력해보자
	for (int i = 0; i < home_count; i++)
	{
		for (int j = 0; j < chicken_count; j++)
		{
			Chicken_distance[i] = min(Chicken_distance[i], from[j][i]);
		}
		totalChicken_distance += Chicken_distance[i];
	}

	return totalChicken_distance;
}

void copy(int array1[][100], int array2[][100])
{
	int* p1, * endp1;
	int* p2;
	p1 = &array1[0][0];
	p2 = &array2[0][0];
	endp1 = &array1[13 - 1][100 - 1];
	while (p1 <= endp1)
	{
		*p2 = *p1;
		p1++; p2++;
	}
}

// n은 치킨집, r은 제외한 치킨집
void Combination(int from[][100], vector<int> comb, int r, int index, int depth)
{
	int arr[13][100];
	copy(from, arr);

	if (r == 0)
	{
		for (int i = 0; i < chicken_count - comb.size(); i++)
		{
			for (int j = 0; j < home_count; j++)
			{
				from[i][j] = 9999;
			}
		}

		cout << ChickenDistance(home_count, chicken_count) << endl;
		//result = min(result, ChickenDistance(home_count, chicken_count));

		for (int i = 0; i < chicken_count - comb.size(); i++)
		{
			for (int j = 0; j < home_count; j++)
			{
				from[i][j] = arr[i][j];
			}
		}
		
	}
	else if (depth == chicken_count - comb.size())  // depth == n
	{
		return;
	}
	else
	{
		comb[index] = from[0][depth];
		Combination(from, comb, r - 1, index + 1, depth + 1);
		Combination(from, comb, r, index, depth + 1);
	}
}

int main()
{
	// 첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.
	cin >> N >> M;

	// 조합 크기 설정
	vector<int> comb(M);
	// 배열 초기화
	for (int i = 0; i < 2*N; i++)
		Chicken_distance[i] = 9999;
	

	// 맵 생성
	int map[50][50] = { 0, };
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

	// 치킨집을 기준으로 각 집에대한 거리를 가지기로 하자
	for (int i = 0; i < chicken_count; i++)
	{
		for (int j = 0; j < home_count; j++)
		{
			from[i][j] = distance(pos_Chicken[i], pos_home[j]);
		}
	}

	Combination(from, comb, M, 0, 0);

	cout << result << endl;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define SIZE 8

typedef struct pos
{
	int y;
	int x;
}Pos;

int N, M;
int map[SIZE][SIZE];
int safetyDomain = 0;

// 이동을 위한 배열
// 순서대로 위쪽, 왼쪽, 아래, 오른쪽
int deltaY[4] = { -1, 0, 1, 0 };
int deltaX[4] = { 0, -1, 0, 1 };

void virusSpread(int map[][SIZE])
{
	queue<Pos> v;
	int found[SIZE][SIZE] = { 0, };

	// 바이러스의 위치를 파악한다.
	// Queue에 저장
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2)
			{
				Pos pos = { i,j };
				v.push(pos);
			}
		}
	}

	// 바이러스를 퍼트린다.
	// 모든 바이러스를 처리하는동안 반복한다.
	while (!v.empty())
	{
		Pos pos = v.front();
		v.pop();

		// 순서대로 위쪽, 왼쪽, 아래, 오른쪽
		for (int i = 0; i < 4; i++)
		{
			int nextY = pos.y + deltaY[i];
			int nextX = pos.x + deltaX[i];

			// 입력한 맵의 크기를 벗어나면 건너뜀
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
				continue;
			// 벽이면 건너뜀
			if (map[nextY][nextX] == 1)
				continue;
			// 이미 바이러스가 퍼진 곳이면 건너뜀
			if (found[nextY][nextX] == 1)
				continue;

			// 감염
			found[nextY][nextX] = 1;
			map[nextY][nextX] = 2;

			// 감염지로부터 다시 시작
			Pos push_pos = { nextY, nextX };
			v.push(push_pos);
		}
	}
}

int count_safetyDomain()
{
	// 벽이 세워진 상태에서 안전구역 저장
	int result = 0;

	// 맵을 복사하고
	int temp_map[SIZE][SIZE];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp_map[i][j] = map[i][j];

	// 바이러스 확산
	virusSpread(temp_map);

	// 안전구역을 카운트한다.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp_map[i][j] == 0)
				result++;
	
	return result;
}

// 벽 세우기
void Wall(Pos pos, int set)
{
	if (set == 1)
		map[pos.y][pos.x] = 1;

	if (set == 0)
		map[pos.y][pos.x] = 0;
}

int main()
{
	// 첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
	cin >> N >> M;

	// 둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
	// 빈 칸의 개수는 3개 이상이다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	// 빈칸 세기
	vector<Pos> pos_Empty;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Pos pos = { i, j };
			if (map[i][j] == 0)
				pos_Empty.push_back(pos);
		}
	}

	// 벽으로 막기
	for (int i = 0; i < pos_Empty.size() - 2; i++)
	{
		Wall(pos_Empty[i], 1);
		for (int j = i + 1; j < pos_Empty.size() - 1; j++)
		{
			Wall(pos_Empty[j], 1);
			for (int k = j + 1; k < pos_Empty.size(); k++)
			{
				Wall(pos_Empty[k], 1);

				// 가장 큰 값 저장
				safetyDomain = max(count_safetyDomain(), safetyDomain);

				Wall(pos_Empty[k], 0);
			}
			Wall(pos_Empty[j], 0);
		}
		Wall(pos_Empty[i], 0);
	}

	// 얻을 수 있는 안전 영역의 최대 크기를 출력한다.
	cout << safetyDomain << endl;
}

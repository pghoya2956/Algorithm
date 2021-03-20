// BOJ_16236
// 2152KB, 4ms
/*
N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다.
한 칸에는 물고기가 최대 1마리 존재한다.

아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다. 
가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다. 
아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
	거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다. 
즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다. 
물고기를 먹으면, 그 칸은 빈 칸이 된다.

아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 
예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <queue>

using namespace std;

typedef struct shark
{
	pair<int, int> _pos;
	int _size = 2;
	int _experience = 0;
}Shark;
Shark shark;

typedef struct fish
{
	pair<int, int> _pos;
	int _distance;
}Fish;

struct compare
{
	bool operator()(Fish a, Fish b)
	{
		// 거리가 같으면
		if (a._distance == b._distance)
			return a._pos > b._pos;				// y, x 순으로 작은걸 높은 우선순위로
		else
			return a._distance > b._distance;	// 거리 낮은걸 높은 우선순위로
	}
};

int N;
int** map;
bool** visited;
int** m_distance;
int second = 0;
// 위, 왼쪽, 아래, 오른쪽 순서로 한다 해도 그냥 큐로 하면 예외상황이 생김
// 원하는 조건의 물고기 먼저 꺼내기 위한 우선순위 큐
priority_queue<Fish, vector<Fish>, compare> Candidate;

int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
void BFS(pair<int, int> pos)
{
	// 탐색하기 위한 큐
	queue<pair<int, int>> q;
	q.push(pos);
	visited[pos.first][pos.second] = true;

	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();

		// 위, 왼쪽, 아래, 오른쪽
		for (int i = 0; i < 4; i++)
		{
			int nextY = temp.first + moveY[i];
			int nextX = temp.second + moveX[i];

			// 맵을 벗어나면 다른 방향으로
			if (nextY >= N || nextY < 0 || nextX >= N || nextX < 0)
				continue;
			// 상어 크기보다 큰 물고기가 있다면 다른 방향으로
			if (map[nextY][nextX] > shark._size)
				continue;
			// 방문했다면 다른 방향으로
			if (visited[nextY][nextX] == true)
				continue;

			// 다음 차례 넣고(방문표시, 거리계산)
			q.push({ nextY, nextX });
			visited[nextY][nextX] = true;
			m_distance[nextY][nextX] =  m_distance[temp.first][temp.second] + 1;

			// 먹을 수 있는 물고기를 찾으면 후보 물고기에 저장
			if (map[nextY][nextX] < shark._size && map[nextY][nextX] != 0)
			{
				Fish fish = { {nextY, nextX }, m_distance[nextY][nextX] };
				Candidate.push(fish);
			}
		}
	}
	// 방문기록, 거리 초기화
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;
			m_distance[i][j] = 0;
		}
	}
}

// 1. 먹을 수 있는 물고기를 찾아서 priority queue에 저장한다.(가장 위, 가장 왼쪽 우선순위).
// 2. 먹을 수 있는 물고기가 없다면 종료
// 3. queue에 물고기가 없을 때 까지 반복
	// 2.1 queue에서 후보 물고기를 꺼낸다
	// 2.2 물고기를 먹는다.(상어 경험치 증가, 사이즈 증가 처리)
	// 2.3 원래 있던 자리와 물고기를 먹은 자리를 0으로 만든다.
	// 2.4 다시 탐색
void GameStart()
{
	// 넓이 탐색
	BFS(shark._pos);

	// 잡아 먹을수 있는 물고기가 있는동안 반복 
	while (!Candidate.empty())
	{
		// 원래 상어가 있던 위치 초기화(제일 처음 상어의 위치 초기화를 위함)
		map[shark._pos.first][shark._pos.second] = 0;

		Fish fish = Candidate.top();
		Candidate.pop();
		
		// 거리 증가
		second += fish._distance;

		// 상어 위치 이동
		shark._pos = fish._pos;

		// 상어 경험치 증가
		shark._experience++;

		// 경험치 찼으면 크기 증가
		if (shark._experience == shark._size)
		{
			shark._experience = 0;
			shark._size++;
		}

		// 맵은 빈칸이 됨
		map[shark._pos.first][shark._pos.second] = 0;

		// 우선순위 큐도 초기화
		while (!Candidate.empty())
		{
			Candidate.pop();
		}

		// 다시 탐색
		BFS(shark._pos);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.
	cin >> N;
	map = new int*[N];
	visited = new bool* [N];
	m_distance = new int* [N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
		visited[i] = new bool[N] {false, };
		m_distance[i] = new int[N] {0, };
	}

	// 둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			// 상어 초기 위치 저장
			if (map[i][j] == 9)
				shark._pos = { i,j };
		}
	}

	// 상어 물고기 잡이 시작
	GameStart();

	// 첫째 줄에 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간을 출력한다.
	cout << second;

	return 0;
}
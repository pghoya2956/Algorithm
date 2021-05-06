// BOJ_14499
// 2148KB, 0ms
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int** map;
int K;
vector<int> commands;

typedef struct dice
{
	pair<int, int> dice_pos;
	// 위, 뒤, 오른쪽, 왼쪽, 앞, 아래
	int direction[6] = { 0, };
}Dice;
Dice _dice;

// 이동(동쪽, 서쪽, 북쪽, 남쪽)
pair<int, int> nextPos[4] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

void rollofDice()
{
	while (!commands.empty())
	{
		// 명령을 꺼낸다.
		int command = commands.front();
		commands.erase(commands.begin());

		// 명령에 따른 주사위의 다음 위치
		int nextY = _dice.dice_pos.first + nextPos[command-1].first;
		int nextX = _dice.dice_pos.second + nextPos[command-1].second;


		// 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.
		if (nextY >= N || nextY < 0 || nextX < 0 || nextX >= M)
			continue;

		// 주사위의 위치를 변경하고
		_dice.dice_pos = { nextY, nextX };

		// 주사위를 회전시킨다.
		int temp[6] = { _dice.direction[0], _dice.direction[1], _dice.direction[2], _dice.direction[3], _dice.direction[4], _dice.direction[5] };
		switch (command)
		{
		case 1:	// 동쪽
			_dice.direction[0] = temp[3];
			_dice.direction[2] = temp[0];
			_dice.direction[3] = temp[5];
			_dice.direction[5] = temp[2];
			break;
		case 2:	// 서쪽
			_dice.direction[0] = temp[2];
			_dice.direction[2] = temp[5];
			_dice.direction[3] = temp[0];
			_dice.direction[5] = temp[3];
			break;
		case 3: // 북쪽
			_dice.direction[0] = temp[4];
			_dice.direction[1] = temp[0];
			_dice.direction[4] = temp[5];
			_dice.direction[5] = temp[1];
			break;
		case 4: // 남쪽
			_dice.direction[0] = temp[1];
			_dice.direction[1] = temp[5];
			_dice.direction[4] = temp[0];
			_dice.direction[5] = temp[4];
			break;
		}

		// 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
		// 현재 위치의 맵
		if (map[_dice.dice_pos.first][_dice.dice_pos.second] == 0)
		{
			map[_dice.dice_pos.first][_dice.dice_pos.second] = _dice.direction[5];
		}
		else	// 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
		{
			_dice.direction[5] = map[_dice.dice_pos.first][_dice.dice_pos.second];
			map[_dice.dice_pos.first][_dice.dice_pos.second] = 0;
		}

		cout << _dice.direction[0] << '\n';
	}
}

int main()
{
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	// 첫째 줄에 지도의 세로 크기 N, 가로 크기 M (1 ≤ N, M ≤ 20)
	cin >> N >> M;
	map = new int* [N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[M];
	}

	// 주사위를 놓은 곳의 좌표 x y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1)
	cin >> _dice.dice_pos.first >> _dice.dice_pos.second;

	// 그리고 명령의 개수 K (1 ≤ K ≤ 1,000)가 주어진다.
	cin >> K;

	// 둘째 줄부터 N개의 줄에 지도에 쓰여 있는 수가 북쪽부터 남쪽으로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다. 
	// 주사위를 놓은 칸에 쓰여 있는 수는 항상 0이다. 
	// 지도의 각 칸에 쓰여 있는 수는 10을 넘지 않는 자연수 또는 0이다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	// 마지막 줄에는 이동하는 명령이 순서대로 주어진다. 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		commands.push_back(temp);
	}

	// 솔루션
	rollofDice();

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int M, N;
char map[50][50];
int answer = 9999;

// 시작인덱스를 기준으로 8*8 크기 체스판 조사
int solution(int istart, int jstart)
{
	int count1 = 0, count2 = 0;
	char temp1, temp2;

	for (int i = istart; i < istart + 8; i++)
	{
		for (int j = jstart; j < jstart + 8; j++)
		{
			// 체스판의 맨 왼쪽 위칸이 흰색인 경우, 검은색인 경우를 처리한다.
			if ((i + j) % 2 == 0)
			{
				temp1 = 'B';
				temp2 = 'W';
			}
			else
			{
				temp1 = 'W';
				temp2 = 'B';
			}

			// 바꿔야 하는 개수
			if (map[i][j] != temp1)
				count1++;

			if (map[i][j] != temp2)
				count2++;
		}
	}

	// 2가지 경우중 작은 경우를 반환한다.
	return min(count1, count2);
}

int main()
{
	// 첫째 줄에 N과 M이 주어진다.N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
	cin >> N >> M;

	// 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다.B는 검은색이며, W는 흰색이다.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++)
	{
		// 8*8개의 체스판을 선택할 수 없을 때 그만한다.
		if (i > N - 8)
			break;

		for (int j = 0; j < M; j++)
		{
			// 8*8개의 체스판을 선택할 수 없을 때 그만한다.
			if (j > M - 8)
				break;

			answer = min(answer, solution(i, j));
		}
	}

	cout << answer;
}

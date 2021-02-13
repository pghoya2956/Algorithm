#include <iostream>
#include <algorithm>

using namespace std;

int N;

// 사람 정보
struct person
{
	int ranking = 1;
	int x = 0;
	int y = 0;
};

int main()
{
	struct person p[50];

	// 첫 줄에는 전체 사람의 수 N이 주어진다.
	// 그리고 이어지는 N개의 줄에는 각 사람의 몸무게와 키를 나타내는 양의 정수 x와 y가 하나의 공백을 두고 각각 나타난다.
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> p[i].x >> p[i].y;
	}

	// 각 사람마다 다른사람과 비교해서 자신보다 덩치가 크다면 랭킹을 하나씩 내린다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (p[i].x < p[j].x && p[i].y < p[j].y)
				p[i].ranking++;
		}
	}

	// 랭킹 출력
	for (int i = 0; i < N; i++)
		cout << p[i].ranking << " ";

	return 0;
}

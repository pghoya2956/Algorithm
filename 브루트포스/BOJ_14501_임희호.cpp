#include <iostream>

using namespace std;
#define MAX(X, Y) X > Y? X : Y

int N = 0;
int T[20] = { 0, };
int P[20] = { 0, };
int value[20] = { 0, };
int answer = 0;

void input()
{
	// 첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.
	while (N < 1 || N > 15)
		cin >> N;

	// 둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1, 000)
	for (int i = 0; i < N; i++)
	{
		cin >> T[i] >> P[i];
	}
}

int solution(int index)
{
	// 재귀함수에서 다음 시작할 인덱스
	int nextIndex = index + T[index];

	// 수행 불가
	if (nextIndex > N)
		return 0;
	// 수행하고 리턴
	if (nextIndex == N)
		return P[index];
	
	for (int i = nextIndex; i < N; i++)
	{
		int temp = solution(i) + P[index];
		value[index] = MAX(value[index], temp);
	}

	return value[index];
}

int solution(int index, int Profit)
{
	if (index == N)
		return MAX(answer, Profit + P[index]);

	if (index > N)
		return 0;

	return MAX(
		solution(index + T[index], Profit + P[index]),
		solution(index + 1, Profit)
	);
}

int main()
{
	input();

	/*for (int i = 0; i < N; i++)
	{
		answer = MAX(answer, solution(i));
	}

	cout << answer << endl;*/

	cout << solution(0, 0) << endl;

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int N = 0;
int* T;
int* P;
int result = 0;
int value = 0;

void input()
{
	// 첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.
	while (N < 1 || N > 15)
		cin >> N;

	// 동적 할당
	T = new int[N];
	P = new int[N];

	// 둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1, 000)
	for (int i = 0; i < N; i++)
	{
		cin >> T[i] >> P[i];
	}
}

void solution(int index)
{
	static int temp = 0;

	int nextIndex = index + T[index];
	if (nextIndex > N)
	{
		return;
	}
	
	temp += P[index];

	for (int i = nextIndex; i < N; i++)
	{
		solution(nextIndex);
		cout << temp << " ";
		value = max(value, temp);
	}

}

int main()
{
	input();

	solution(0);
	result = value;
	for (int i = 1; i < N; i++)
	{
		value = 0;
		solution(i);
		result = max(result, value);
	}

	cout << result << endl;

	return 0;
}
// BOJ_12852
// 56580KB, 48ms
/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
연산을 사용하는 횟수의 최솟값을 출력하시오.*/
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> N[1000001];

int DP(int start)
{
	if (start == 1)
		return 0;

	if (N[start].first != 0)
		return N[start].first;

	// 1을 뺀다.
	N[start] = { DP(start - 1) + 1, start - 1 };

	// X가 3으로 나누어 떨어지면, 3으로 나눈다.
	// 위의 경우보다 좋은 조건을 찾는 경우에만 실행한다
	if (start % 3 == 0 && DP(start / 3) < N[start].first)
		N[start] = { DP(start / 3) + 1, start / 3 };

	// X가 2로 나누어 떨어지면, 2로 나눈다.
	// 위의 경우보다 좋은 조건을 찾는 경우에만 실행한다
	if (start % 2 == 0 && DP(start / 2) < N[start].first)
		N[start] = { DP(start / 2) + 1, start / 2 };

	return N[start].first;
}

int main()
{
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int number;
	cin >> number;

	cout << DP(number) << '\n';

	// 자신의 자식 인덱스를 출력한다음 자식의 자식을 출력하기 위해 인덱스를 이동한다.
	cout << number << " ";
	while (N[number].second != 0)
	{
		cout << N[number].second << " ";
		number = N[number].second;
	}

	return 0;
}

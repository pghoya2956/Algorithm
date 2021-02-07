#include <iostream>
#include <string>

using namespace std;

int N = 0;
int MIN_Constructor = 0;

int Decomposition(int n)
{
	int result = 0;
	string str = to_string(n);
	for (int i = 0; i < str.size(); i++)
	{
		result += str[i] - '0';
	}

	return n + result;
}

void solution()
{
	for (int i = 1; i < N; i++)
	{
		if (Decomposition(i) == N)
		{
			MIN_Constructor = i;
			return;
		}
	}
}

int main()
{
	// 첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
	cin >> N;
	
	solution();

	cout << MIN_Constructor << endl;

	return 0;
}
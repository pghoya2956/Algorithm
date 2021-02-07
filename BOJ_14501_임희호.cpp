#include <iostream>
#include <random>
#include <vector>
#include <functional>

using namespace std;

int N = 0;
vector<int> T;
vector<int> P;

void input()
{
	// 첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.
	while (N < 1 || N > 15)
		cin >> N;

	// 둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1, 000)
	for (int i = 0; i < N; i++)
	{
		int ValueT = 0, ValueP = 0;
		while ((ValueT < 1 || ValueT > 5) || (ValueP < 1 || ValueP > 1000))
			cin >> ValueT >> ValueP;

		T.push_back(ValueT);
		P.push_back(ValueP);
	}
}

int ConsultingProcess()
{
	// 최대 수익
	int MAX_P = 0;
	vector<int, int> caseT;

	// 입력한 N에서 경우의 수를 살펴본다.
	int i = 0;
	while (i < N)
	{
		int temp_T = 0;
		while (temp_T + T[temp_T] <= N)
		{
			caseT.push_back(T[temp_T]);
			temp_T += T[temp_T];

			if (temp_T >= N)
				break;
		}

		i++;
	}

	return MAX_P;
}


int main()
{
	input();
	
	cout << ConsultingProcess() << endl;


	return 0;
}
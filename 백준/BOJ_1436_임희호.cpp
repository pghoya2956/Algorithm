#include <iostream>
#include <string>

using namespace std;

int N;

int main()
{
	// 첫째 줄에 숫자 N이 주어진다. N은 10,000보다 작거나 같은 자연수이다.
	cin >> N;

	int N_count = 0;

	// N번째로 작은 종말의 수를 찾는다.
	int i = 665;
	while (N_count != N)
	{
		// 666부터 시작해서 차례대로 검사
		string str = to_string(++i);
		for (int i = 0; i < str.size() - 2; i++)
		{
			// 연속된 666이 나오면 종말의 수이므로 N_count번째로 작은 종말의 수임
			if (str[i] - '0' == 6 && str[i + 1] - '0' == 6 && str[i + 2] - '0' == 6)
			{
				N_count++;
				break;
			}
		}
	}

	cout << i;
}

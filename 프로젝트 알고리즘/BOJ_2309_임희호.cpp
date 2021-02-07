#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 아홉난쟁이
vector<int> N;

int main()
{
	int sum = 0;
	// 아홉 개의 줄에 걸쳐 난쟁이들의 키가 주어진다. 주어지는 키는 100을 넘지 않는 자연수이며, 아홉 난쟁이의 키는 모두 다르다.
	for (int i = 0; i < 9; i++)
	{
		int num;
		cin >> num;
		sum += num;

		N.push_back(num);
	}

	// 가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (N[i] + N[j]) == 100)
			{
				// 인덱스가 더 큰 j부터 삭제해야 한다. 두 명 삭제해서 일곱 난쟁이
				N.erase(N.begin() + j);
				N.erase(N.begin() + i);

				// 처음 나온 결과를 출력한다.
				goto EXIT;
			}
		}
	}
EXIT:
	// vector을 오름차순으로 정렬
	sort(N.begin(), N.end());
	for (auto i = N.begin(); i < N.end(); i++)
	{
		cout << *i << endl;
	}

	return 0;
}
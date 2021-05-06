// BOJ_2467
// 2408KB, 12ms
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int* v;

int main()
{
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);


	// 첫째 줄에는 전체 용액의 수 N이 입력된다. N은 2 이상 100,000 이하의 정수이다. 
	cin >> N;

	// 둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 오름차순으로 입력되며,
	// 이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다.
	v = new int[N];
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int _min = INT32_MAX;
	int L = 0, R = 0;

	int low = 0;
	int high = N - 1;
	while (low < high)
	{
		int temp = abs(v[low] + v[high]);

		if (temp < _min)
		{
			_min = temp;
			L = low;
			R = high;
		}

		if (abs(v[low + 1] + v[high]) < abs(v[low] + v[high - 1]))
			low++;
		else
			high--;
	}

	cout << v[L] << " " << v[R] << '\n';

	return 0;
}



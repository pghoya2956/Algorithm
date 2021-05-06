// BOJ_2166
// 2176KB, 4ms
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
pair<double, double>* v;

int main()
{
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	
	// 첫째 줄에 N이 주어진다. 
	cin >> N;

	// 다음 N개의 줄에는 다각형을 이루는 순서대로 N개의 점의 x, y좌표가 주어진다. 좌표값은 절댓값이 100,000을 넘지 않는 정수이다.
	v = new pair<double, double>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first;
		cin >> v[i].second;
	}
		
	double answer = 0.0;
	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
		{
			answer += (v[i].first+v[0].first) * (v[i].second - v[0].second);
			answer = abs(answer);
			answer /= 2;
			break;
		}
		answer += (v[i].first + v[i + 1].first) * (v[i].second - v[i + 1].second);
	}
	
	printf("%.1lf\n", answer);

	return 0;
}

// BOJ_1654
// 2284KB, 4ms
/*
집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.
이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에
K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)
편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자.
그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다.
이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K, N;
vector<long long> v;
long long answer = 0;

void BinarySearch(long long start, long long end)
{
	if (start > end)
		return;

	// start와 end를 더했을 때 2^31 - 1을 넘는 overflow방지
	long long mid = (start + end) / 2;

	int sum = 0;
	for (int i = 0; i < K; i++)
		sum += v[i] / mid;

	// 목표 갯수와 같거나 크다면(따로 처리하면 오답)
	if (sum >= N)
	{
		answer = max(answer, mid);
		BinarySearch(mid + 1, end);
	}
	// 개수에 미치지 못한다면
	else
		BinarySearch(start, mid - 1);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. 
	cin >> K >> N;

	// K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다.
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	// 가장 큰 값 구함
	long long end = *max_element(v.begin(), v.end());
	BinarySearch(1, end);

	// 출력
	cout << answer << '\n';

	return 0;
}
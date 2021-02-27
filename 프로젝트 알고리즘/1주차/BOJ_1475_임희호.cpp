#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N = 0;
int CardCase[9] = { 0, };

int solution(int n)
{
	// 문자열로 변환해서 해당 숫자의 카드의 개수를 추가한다. 
	string str = to_string(n);
	for (int i = 0; i < str.size(); i++)
	{
		int num = str[i] - '0';
		if (num != 6 && num != 9)
			CardCase[num]++;
		else
			CardCase[6]++;
	}
	
	// 한 셋트에 6과 9는 2장씩 나오므로 홀수 개일때를 생각해서 1더하여 2로 나눠주고
	// 가장 큰 값(필요한 셋트수)를 찾는다.
	CardCase[6] = (CardCase[6] + 1) / 2;
	int result = 0;
	for (int i = 0; i < 9; i++)
	{
		result = max(result, CardCase[i]);
	}

	return result;
}

int main()
{
	// 첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수 또는 0이다.
	cin >> N;
	
	cout << solution(N) << endl;

	return 0;
}
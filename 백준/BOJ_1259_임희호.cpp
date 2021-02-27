// BOJ_1259
// 2016KB, 0ms
/*
어떤 단어를 뒤에서부터 읽어도 똑같다면 그 단어를 팰린드롬이라고 한다. 'radar', 'sees'는 팰린드롬이다.
수도 팰린드롬으로 취급할 수 있다. 수의 숫자들을 뒤에서부터 읽어도 같다면 그 수는 팰린드롬수다. 121, 12421 등은 팰린드롬수다.
123, 1231은 뒤에서부터 읽으면 다르므로 팰린드롬수가 아니다. 
또한 10도 팰린드롬수가 아닌데, 앞에 무의미한 0이 올 수 있다면 010이 되어 팰린드롬수로 취급할 수도 있지만, 특별히 이번 문제에서는 무의미한 0이 앞에 올 수 없다고 하자.
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool IsPalindrome(string s)
{
	// 문자열 크기의 반만큼 탐색
	for (int i = 0; i <= (s.size() - 1) / 2; i++)
	{
		// 다른게 나오면 실패
		if (s[i] != s[s.size() - (i + 1)])
			return false;
	}
	// 모두 같다면 참
	return true;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1)
	{
		int inum;
		cin >> inum;
		if (inum == 0)
			break;

		// 문자열로 바꿔서 입력
		if (IsPalindrome(to_string(inum)))
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}

	return 0;
}
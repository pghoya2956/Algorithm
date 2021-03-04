// BOJ_1157
// 3672 KB, 12 ms
/*
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

// 알파벳 개수
int a[26] = { 0, };
int max_value = 0;
char answer;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다.
	string s;
	cin >> s;

	// 알파벳(26개)을 저장하는 배열 a에 대소문자 구분없이 개수를 카운팅한다. 
	for (char c : s)
	{
		// 소문자
		if (c >= 97 && c <= 122)
			a[c - 97]++;
		// 대문자
		if (c >= 65 && c <= 90)
			a[c - 65]++;
	}

	// 가장 큰 값을 가진 인덱스의 알파벳을 저장한다.
	for (int i = 0; i < 26; i++)
	{
		// 가장 큰 값으로 문자 저장
		if (a[i] > max_value)
		{
			answer = i + 65;
			max_value = a[i];
		}	
	}

	// 가장 큰 값을 가진 중복된 인덱스가 있으면 '?'로 변환한다.
	int count = 0;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] == max_value)
			count++;

		if (count >= 2)
		{
			answer = '?';
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}
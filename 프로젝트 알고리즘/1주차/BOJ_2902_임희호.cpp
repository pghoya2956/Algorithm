#include <iostream>
#include <string>

using namespace std;

int main()
{
	/* 입력은 한 줄로 이루어져 있고, 최대 100글자의 영어 알파벳 대문자, 소문자, 그리고 하이픈 ('-', 아스키코드 45)로만 이루어져 있다.
	첫 번째 글자는 항상 대문자이다. 그리고, 하이픈 뒤에는 반드시 대문자이다. 그 외의 모든 문자는 모두 소문자이다.*/
	string str;
	cin >> str;

	// 짧은 형태 기록
	cout << str[0];
	for (int i = 1; i < str.size(); i++)
	{
		// 하이픈 뒤의 문자를 출력, 마지막 문자가 하이픈이라면 무시
		if (str[i] == '-' && i != str.size() - 1)
			cout << str[i + 1];
	}
}
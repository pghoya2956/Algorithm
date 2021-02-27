/* BOJ_1181
* 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
* 길이가 짧은 것부터
* 길이가 같으면 사전 순으로
* 
* 4644KB, 44ms
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<string> v;

bool MyCompare(string s1, string s2)
{
	if(s1.size() != s2.size())
		return s1.size() < s2.size();
	
	return s1 < s2;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다.
	// 주어지는 문자열의 길이는 50을 넘지 않는다.
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	// 조건에 따라 정렬
	sort(v.begin(), v.end(), MyCompare);

	// 벡터 중복제거 하는 방법
	/* unique함수는 vector 내부를 위 그림과 같이 바꿔주고 자신이 바꾼 vector의 end() 부분을 반환
	* erase 함수는 vector에서 특정 원소를 삭제하는 함수 */
	v.erase(unique(v.begin(), v.end()), v.end());

	// 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}

	return 0;
}
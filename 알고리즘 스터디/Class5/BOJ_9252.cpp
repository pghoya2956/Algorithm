// BOJ_9252
// 5980KB, 4ms
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string S1, S2;
vector<char> v;

int main()
{
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> S1;
	cin >> S2;
	int** LCS;
	LCS = new int* [S1.length()+1];
	for (int i = 0; i<= S1.length(); i++)
	{
		LCS[i] = new int[S2.length()+1]{ 0, };
	}

	for (int i = 1; i <= S1.length(); i++)
	{
		for (int j = 1; j <= S2.length(); j++)
		{
			// 수를 비교해 같을 경우 왼쪽 위 대각선 값에 1을 더해 저장
			if (S1[i-1] == S2[j-1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else	// 다를 경우 좌측 혹은 상단의 값중 큰 값을 저장
				LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);

		}
	}

	// 가장 오른쪽 아래부터
	int j = S2.length();
	for (int i = S1.length(); i >= 1; i--)
	{
		while (j >= 1)
		{
			// 왼쪽하고 같으면 왼쪽으로
			if (LCS[i][j] == LCS[i][j - 1])
			{
				j--;
				continue;
			}

			// 위쪽과 같으면 위쪽으로
			if (LCS[i][j] == LCS[i - 1][j])
				break;

			// 아니면 현재 위치의 문자를 저장하고 왼쪽위 대각선으로
			v.push_back(S1[i-1]);
			i--;
			j--;
		}
	}

	// 
	cout << v.size() << '\n';
	for (int i = v.size()-1; i >= 0; i--)
		cout << v[i];

	return 0;
}

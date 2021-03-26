// BOJ_2644
// 2056KB, 0ms
/*
우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 단위로 표현하는 독특한 문화를 가지고 있다. 

이러한 촌수는 다음과 같은 방식으로 계산된다. 기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를 계산한다. 

예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고, 아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.

여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산하는 프로그램을 작성하시오.
*/
#include <iostream>

using namespace std;

int N;
int map[101][101] = { 0, };
bool check[101] = { false };
int answer = -1;

// num1은 현재노드, num2는 찾는 노드
void DFS(int num1, int num2, int cnt)
{
	check[num1] = true;

	// 친척 관계를 찾았으면 촌수 리턴
	if (num1 == num2)
		answer = cnt;
		
	// 친척을 찾는다. 
	for (int i = 1; i <= N; i++)
	{
		if (map[num1][i] != 1)
			continue;
		if (check[i] != false)
			continue;

		DFS(i, num2, cnt+1);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 입력 파일의 첫째 줄에는 전체 사람의 수 n이 주어지고
	cin >> N;

	// 둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다
	int num1, num2;
	cin >> num1 >> num2;

	// 셋째 줄에는 부모 자식들 간의 관계의 개수 m이 주어진다. 
	int line;
	cin >> line;

	// 넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다.
	for (int i = 0; i < line; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
		map[x][y] = 1;
	}

	// 촌수 탐색
	DFS(num1, num2, 0);

	// 입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다. 
	// 어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다. 이때에는 -1을 출력해야 한다.
	cout << answer;

	return 0;
}
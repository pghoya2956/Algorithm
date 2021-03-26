// BOJ_2667
// 2020KB, 12ms
/*
 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
 
 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. 

 <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 

 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string* map;
bool check[25][25] = { false };
vector<int> v;

int cnt;

void DFS(int y, int x)
{
	int moveY[4] = { 1,0,-1,0 };
	int moveX[4] = { 0,-1,0,1 };

	// 현재 위치 방문 체크
	check[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];

		// 연결된 부분만 탐색
		if (nextY <0 || nextY>=N || nextX < 0 || nextX>=N)
			continue;
		if (check[nextY][nextX] != false)
			continue;
		if (map[nextY][nextX] == '0')
			continue;

		DFS(nextY, nextX);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고
	cin >> N;

	// 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.
	map = new string[N];
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	// 맵 탐색
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 집이 있는 칸에서만 DFS 탐색하기		
			if (map[i][j] == '0')
				continue;
			if (check[i][j] != false)
				continue;

			cnt = 0;
			DFS(i, j);
			v.push_back(cnt);
		}
	}

	// 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
	int n = v.size();
	cout << n << endl;
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i<n; i++)
	{
		cout << v.back() << endl;
		v.pop_back();
	}

	return 0;
}
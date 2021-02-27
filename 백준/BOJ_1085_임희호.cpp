/*
* 한수는 지금 (x, y)에 있다. 직사각형의 왼쪽 아래 꼭짓점은 (0, 0)에 있고, 오른쪽 위 꼭짓점은 (w, h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.
* 2016KB, 0ms
*/
#include <iostream>
#include <algorithm>

using namespace std;

int x, y, w, h;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 x, y, w, h가 주어진다.
	cin >> x >> y >> w >> h;

	cout << min(min(h-y, y), min(w-x, x)) << '\n';

	return 0;
}
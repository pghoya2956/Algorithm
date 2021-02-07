#include <iostream>
#include <string>

using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	// n번째 피보나치 수 저장
	int result = 0;
	// n번째 피보나치 수의 앞선 두 값을 저장한다.
	int Previous1 = 1;
	int Previous2 = 0;
	// 앞선 두 수를 더하는 작업
	for (int i = 2; i <= n; i++)
	{ 
		result = Previous2 + Previous1;
		Previous2 = Previous1;
		Previous1 = result;
	}

	return result;
}

int main()
{
	// 첫째 줄에 n이 주어진다. n은 45보다 작거나 같은 자연수이다.
	int n;
	cin >> n;
	
	cout << Fibonacci(n) << endl;

	return 0;
}
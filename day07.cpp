//fibonacciÊýÁÐ
#include <iostream>
#include <algorithm>
using namespace std;
int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}
int main()
{
	int N, l = 0, r = 0;

	while (cin >> N)
	{
		int i = 0;
		while (i < N)
		{
			if (fib(i) <= N && fib(i + 1) >= N)
			{
				l = N - fib(i);
				r = fib(i + 1) - N;
				break;
			}
			i++;
		}
		cout << min(l, r);
	}
	return 0;
}

//À¨ºÅÆ¥Åä
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int count = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			count++;
		}
		else if (s[i] == ')' && count != 0)
		{
			count--;
		}
		else if (s[i] == ')' && count == 0)
		{
			return false;
		}
	}
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	return 0;
}
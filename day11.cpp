//查找组成一个偶数最接近的两个素数
#include <iostream>
using namespace std;
bool Leap(int n)
{
	if (n == 1 || n == 2)
		return true;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
				return false;
		}
		return true;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n % 2 != 0)
			return 0;
		int start = 0;
		int end = 0;
		for (int i = 0; i <= n / 2; i++)
		{
			if (Leap(i) && Leap(n - i))
			{
				if (i > start)
				{
					start = i;
					end = n - i;
				}
			}
		}
		cout << start << "\n" << end << endl;
	}

	return 0;
}

//二进制插入
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;
		return m | n;
	}
};

//最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a > b)
			{
				a /= 2;
			}
			else
			{
				b /= 2;
			}
		}
		return a;
	}
};

//求最大bit连续数
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i;
	while (cin >> i)
	{
		int count = 0;
		int max_count = 0;
		while (i)
		{
			if (i & 1)
			{
				++count;
				max_count = max(count, max_count);
			}
			else
			{
				count = 0;
			}
			i = i >> 1;
		}
		cout << max_count << endl;
	}
	return 0;
}
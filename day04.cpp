/*A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。
输入描述 :
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。
范围均在 - 30到30之间(闭区间)。

输出描述 :
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。
如果不存在这样的整数A，B，C，则输出No*/
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	string s;
	string table = "0123456789ABCDEF";
	int M, N;
	cin >> M >> N;
	while (M)
	{
		if (M < 0)
		{
			M = -M;
			cout << "-";
		}
		s += table[M%N];
		M /= N;
	}
	reverse(s.begin(), s.end());
	cout << s;
	return 0;
}

/*标题：进制转换 | 时间限制：1秒 | 内存限制：32768K
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述：
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述：
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10
用A表示，等等）
*/
#include <iostream>

using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;
	if (B1 == B2)
	{
		cout << A << ' ' << B1 << ' ' << C;
	}
	else
	{
		cout << "No";
	}
	return 0;
}
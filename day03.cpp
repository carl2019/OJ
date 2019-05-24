//读入一个字符串str，输出字符串str中的连续最长的数字串
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str, tmp, ret;
	cin >> str;
	for (int i = 0; i < str.length() + 1; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			tmp += str[i];
		}
		else
		{
			if (tmp.size() > ret.size())
			{
				ret = tmp;
			}
			else
			{
				tmp.clear();
			}
		}
	}
	cout << ret << endl;
	return 0;
}

//n个数里出现次数大于等于n / 2的数
//每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n / 2。
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int n;
	vector <int> v;
	while (cin >> n)
	{
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	cout << v[v.size() / 2 - 1];
	return 0;
}
//����һ���ַ���str������ַ���str�е�����������ִ�
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

//n��������ִ������ڵ���n / 2����
//ÿ������������� n���ո�ָ��n��������n������100��������һ���������ִ������ڵ���n / 2��
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
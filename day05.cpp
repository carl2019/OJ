//连续最大和
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int sum = 0;
	int ret = a[0];
	for (int i = 0; i < n; i++)
	{
		if (sum >= 0)
		{
			sum += a[i];
		}
		else
		{
			sum = a[i];
		}
		if (sum > ret)
		{
			ret = sum;
		}
	}
	cout << ret;
	return 0;
}

//统计回文 
#include <iostream>
#include <string>
using namespace std;
bool ISHuiWen(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
		{
			return false;
		}
		++begin;
		--end;
	}
	return true;
}
int main()
{
	string str1, str2;
	int count = 0;
	getline(cin, str1);
	getline(cin, str2);
	for (size_t i = 0; i <= str1.size(); ++i)
	{
		string str = str1;
		str.insert(i, str2);
		if (ISHuiWen(str))
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
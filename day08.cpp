//两种排序方法
#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;
int dic_sort(vector<string> s, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (strcmp(s[i].c_str(), s[i + 1].c_str()) >0)
		{
			return 0;
		}
	}
	return 1;
}
int len_sort(vector<string> s, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (s[i].length() > s[i + 1].length())
		{
			return 0;
		}

	}
	return 1;

}
int main()
{
	int n;
	cin >> n;
	vector<string> s;
	s.resize(n);
	for (auto& str : s)
		cin >> str;
	if (dic_sort(s, n) == 1 && len_sort(s, n) == 1)
		cout << "both";
	if (dic_sort(s, n) == 1 && len_sort(s, n) == 0)
		cout << "lexicographically";
	if (dic_sort(s, n) == 0 && len_sort(s, n) == 1)
		cout << "lengths";
	if (dic_sort(s, n) == 0 && len_sort(s, n) == 0)
		cout << "none";
	return 0;
}

//求最小公倍数
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 1; i>0; ++i)
	{
		if (i%a == 0 && i%b == 0)
		{
			cout << i;
			break;
		}
	}
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int ret = 1;
		vector <int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		for (int i = 1; i < n - 1; i++)
		{
			if ((v[i - 1] < v[i] && v[i] > v[i + 1]) ||
				(v[i - 1] > v[i] && v[i] < v[i + 1]))
			{
				ret++;
				if (i != n - 3)
				{
					i++;
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}

#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
	{
		s2 = s1 + " " + s2;
		cout << s2 << endl;
	}
	return 0;
}
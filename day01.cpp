//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (auto i = s1.begin(); i != s1.end(); ++i)
	{
		auto tmp = find(s2.cbegin(), s2.cend(), *i);
		if (tmp != s2.cend())
		{
			s1.erase(i);
			--i;
		}
	}
	cout << s1;
	return 0;
}

/*
ţţ�ٰ���һ�α�̱���, �μӱ�������3*n��ѡ��, ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������, һ�����n������, ��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
���� :
һ������������Ա��ˮƽֵ�ֱ���3, 3, 3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���3, 2, 3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���1, 5, 2.��ô�����ˮƽֵ��2
Ϊ���ñ������п���, ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
��������ʾ :
���ţţ��6����Ա���ֵ���������
�������Ϊ :
team1 : {1, 2, 5}, team2 : {5, 5, 8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
���������Ϊ :
team1 : {2, 5, 8}, team2 : {1, 5, 5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
û�б��ܺ�Ϊ10����ķ���, �������10.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector <int> v(3 * n);
		for (int i = 0; i < 3 * n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}
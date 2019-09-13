//电话号码
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <exception>
#include <iomanip>
#include <memory>
#include <sstream>
#define INF 1000000
using namespace std;
int main(int argc, char** argv)
{
	unordered_map<char, char> dic;
	dic.emplace('A', '2');
	dic.emplace('B', '2');
	dic.emplace('C', '2');
	dic.emplace('D', '3');
	dic.emplace('E', '3');
	dic.emplace('F', '3');
	dic.emplace('G', '4');
	dic.emplace('H', '4');
	dic.emplace('I', '4');
	dic.emplace('J', '5');
	dic.emplace('K', '5');
	dic.emplace('L', '5');
	dic.emplace('M', '6');
	dic.emplace('N', '6');
	dic.emplace('O', '6');
	dic.emplace('P', '7');
	dic.emplace('Q', '7');
	dic.emplace('R', '7');
	dic.emplace('S', '7');
	dic.emplace('T', '8');
	dic.emplace('U', '8');
	dic.emplace('V', '8');
	dic.emplace('W', '9');
	dic.emplace('X', '9');
	dic.emplace('Y', '9');
	dic.emplace('Z', '9');
	int n;
	while (cin >> n && n > 0)
	{
		set<string> hs;
		string s;
		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			string p = "";
			for (auto& c : s)
			{
				if (isdigit(c)) p += c;
				else if (isupper(c)) p += dic[c];
			}
			if (p.size() != 7) continue;
			p = p.substr(0, 3) + "-" + p.substr(3);
			hs.emplace(p);
		}
		for (auto& phone : hs) cout << phone << endl;
		cout << endl;
	}
	return 0;
}

//求和
#include<iostream>
#include<vector>
using namespace std;
void help(int n, int m, vector<int>& v, int beg) {
	// m == 0 为递归结束条件. 此时 v 中可能已经包含了若干个元素了. 并且 v 中的内容就是一组结果.
	if (m == 0) {
		for (int i = 0; i<v.size(); i++) {
			// 这个 ? : 只是为了让结果的格式能够和要求一样.
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n&&i <= m; i++) {
		// 以下几行代码是该题目的关键. 问题的转换.
		// 为了求 i -> n 有多少种情况和为 m, 则把问题转换为
		// i + 1 -> n 有多少中情况和为 m - i
		v.push_back(i);
		help(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int>v;
		help(n, m, v, 1);
	}
}
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string pwd;

	while (getline(cin, pwd))
	{
		int score = 0;
		int len = pwd.size();
		if (len <= 4)
			score = 5;
		else if (len >4 && len <8)
			score = 10;
		else if (len >= 8)
			score = 25;
		int lower = 0, upper = 0, num = 0, sym = 0;
		for (int i = 0; i < len; i++)
		{
			if (pwd[i] <= 'z' && pwd[i] >= 'a')
				lower++;
			else if (pwd[i] <= 'Z' && pwd[i] >= 'A')
				upper++;
			else if (pwd[i] <= '9' && pwd[i] >= '0')
				num++;
			else
				sym++;
		}
		if ((lower == 0 && upper != 0) || (lower != 0 && upper == 0))
			score += 10;
		else if (lower != 0 && upper != 0)
			score += 20;
		if (num == 1)
			score += 10;
		else if (num > 1)
			score += 20;
		if (sym == 1)
			score += 10;
		else if (sym > 1)
			score += 25;
		if ((lower != 0 || upper != 0) && num != 0)
			score += 2;
		else if ((lower != 0 || upper != 0) && num != 0 && sym != 0)
			score += 3;
		else if (lower != 0 && upper != 0 && num != 0 && sym != 0)
			score += 5;
		if (score >= 90)
			cout << "VERY_SECURE" << endl;
		else if (score >= 80)
			cout << "SECURE" << endl;
		else if (score >= 70)
			cout << "VERY_STRONG" << endl;
		else if (score >= 60)
			cout << "STRONG" << endl;
		else if (score >= 50)
			cout << "AVERAGE" << endl;
		else if (score >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}

class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		if (board[0][0] + board[1][1] + board[2][2] == 3)
			return true;
		if (board[2][0] + board[1][1] + board[0][2] == 3)
			return true;
		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] + board[i][1] + board[i][2] == 3)
				return true;
			if (board[0][i] + board[1][i] + board[2][i] == 3)
				return true;
		}
		return false;
	}
};
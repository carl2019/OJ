int nextPosition[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
class Solution {
public:
	void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& book,
		int x, int y)
	{
		//����ǰ�߼�
		book[x][y] = 1;
		//����ÿһ�ֿ��ܣ��ĸ�����
		for (int k = 0; k < 4; ++k)
		{
			int nX = x + nextPosition[k][0];
			int nY = y + nextPosition[k][1];
			//�ж���λ���Ƿ�Խ��
			if (nX >= row || nX < 0
				|| nY >= col || nY < 0)
				continue;
			//�������Ҫ�󣬲���֮ǰҲû����Ⱦ�����������Ⱦ
			if (grid[nX][nY] == '1' && book[nX][nY] == 0)
			{
				dfs(grid, row, col, book, nX, nY);
			}
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		int ret = 0;
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> book;
		book.resize(row);
		for (int i = 0; i < row; ++i)
			book[i].resize(col, 0);
		//��ÿһ�������Ϊ��Ⱦ��㿪ʼ
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == '1' && book[i][j] == 0)
				{
					++ret;
					dfs(grid, row, col, book, i, j);
				}
			}
		}
		return ret;
	}
};

//���Թ�
struct node
{
	int x;
	int y;
};
//queueʵ��
bool Bfs(vector<vector<int>> graph, int startx, int starty, int destx, int desty)
{
	//�Թ��Ĵ�С
	int m = graph.size();
	int n = graph[0].size();
	//�洢�Թ��е�λ��
	queue<node> q;
	//����Թ��е�λ���Ƿ��߹�
	vector<vector<int>> book;
	book.resize(m);
	for (size_t i = 0; i < m; i++)
		book[i].resize(n, 0);
	q.push(node(startx, starty));
	//����Ѿ��߹�
	book[startx][starty] = 1;
	//�ĸ����ߵķ�����������
	int next[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	//����Ƿ���Գ�ȥ
	bool flag = false;
	while (!q.empty())
	{
		//��ǰλ�ô��������µ�λ��, ����������������
		for (size_t i = 0; i < 4; ++i)
		{
			//�����µ�λ��
			int nx = q.front()._x + next[i][0];
			int ny = q.front()._y + next[i][1];
			//�µ�λ��Խ�磬������һ��
			if (nx >= m || nx < 0
				|| ny >= n || ny < 0)
			{
				continue;
			}
			//����µ�λ�����ϰ�����֮ǰҲû�߹��������µ�λ��
			if (graph[nx][ny] == 0 && book[nx][ny] == 0)
			{
				q.push(node(nx, ny));
				//����ѱ��߹�
				book[nx][ny] = 1;
			}
			//����µ�λ��ΪĿ��λ��,���������
			if (nx == destx && ny == desty)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;
		//�������µ�λ�ü��������
		q.pop();
	}
	return flag;
}
//vectorʵ��
bool Bfs(vector<vector<int>> graph, int startx, int starty, int destx, int desty)
{
	//�Թ��Ĵ�С
	int m = graph.size();
	int n = graph[0].size();

	//�洢�Թ��е�λ��
	vector<node> queue;
	queue.resize(m*n);


	//����Թ��е�λ���Ƿ��߹�
	vector<vector<int>> book;
	book.resize(m);
	for (size_t i = 0; i < m; i++)
		book[i].resize(n, 0);

	int head = 0;
	int tail = 1;
	queue[head].x = startx;
	queue[head].y = starty;
	//����Ѿ��߹�
	book[startx][starty] = 1;
	//�ĸ����ߵķ�����������
	int next[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	//����Ƿ���Գ�ȥ
	bool flag = false;

	while (head < tail)
	{
		//��ǰλ�ô��������µ�λ��, ����������������
		for (size_t i = 0; i < 4; ++i)
		{
			//�����µ�λ��
			int nx = queue[head].x + next[i][0];
			int ny = queue[head].y + next[i][1];
			//�µ�λ��Խ�磬������һ��
			if (nx >= m || nx < 0
				|| ny >= n || ny < 0)
			{
				continue;
			}
			//����µ�λ�����ϰ�����֮ǰҲû�߹��������µ�λ��
			if (graph[nx][ny] == 0 && book[nx][ny] == 0)
			{
				queue[tail].x = nx;
				queue[tail].y = ny;
				//����ѱ��߹�
				book[nx][ny] = 1;
				++tail;
			}
			//����µ�λ��ΪĿ��λ��,���������
			if (nx == destx && ny == desty)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;
		//�������µ�λ�ü��������
		++head;
	}
	return flag;
}
int main()
{
	int sx, sy, ex, ey;
	vector<vector<int>> graph;
	int m, n;
	cout << "�������Թ��Ĵ�С: �У���" << endl;
	cin >> m >> n;
	graph.resize(m);
	for (size_t i = 0; i < m; ++i)
	{
		graph[i].resize(n);
	}
	cout << "�������Թ���Ԫ��" << endl;
	for (size_t i = 0; i < m; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}
	while (1)
	{
		cout << "�������Թ���ںͳ���" << endl;
		cin >> sx >> sy >> ex >> ey;
		cout << "�Ƿ�����߳��Թ��� " << Bfs(graph, sx, sy, ex, ey) << endl;
	}
	return 0;
}
int nextPosition[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
class Solution {
public:
	void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& book,
		int x, int y)
	{
		//处理当前逻辑
		book[x][y] = 1;
		//遍历每一种可能，四个方向
		for (int k = 0; k < 4; ++k)
		{
			int nX = x + nextPosition[k][0];
			int nY = y + nextPosition[k][1];
			//判断新位置是否越界
			if (nX >= row || nX < 0
				|| nY >= col || nY < 0)
				continue;
			//如果符合要求，并且之前也没有渲染过，则继续渲染
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
		//以每一个网格点为渲染起点开始
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

//走迷宫
struct node
{
	int x;
	int y;
};
//queue实现
bool Bfs(vector<vector<int>> graph, int startx, int starty, int destx, int desty)
{
	//迷宫的大小
	int m = graph.size();
	int n = graph[0].size();
	//存储迷宫中的位置
	queue<node> q;
	//标记迷宫中的位置是否被走过
	vector<vector<int>> book;
	book.resize(m);
	for (size_t i = 0; i < m; i++)
		book[i].resize(n, 0);
	q.push(node(startx, starty));
	//标记已经走过
	book[startx][starty] = 1;
	//四个行走的方向，上下左右
	int next[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	//标记是否可以出去
	bool flag = false;
	while (!q.empty())
	{
		//当前位置带出所有新的位置, 可以向上下左右走
		for (size_t i = 0; i < 4; ++i)
		{
			//计算新的位置
			int nx = q.front()._x + next[i][0];
			int ny = q.front()._y + next[i][1];
			//新的位置越界，继续下一个
			if (nx >= m || nx < 0
				|| ny >= n || ny < 0)
			{
				continue;
			}
			//如果新的位置无障碍并且之前也没走过，保存新的位置
			if (graph[nx][ny] == 0 && book[nx][ny] == 0)
			{
				q.push(node(nx, ny));
				//标记已被走过
				book[nx][ny] = 1;
			}
			//如果新的位置为目标位置,则结束查找
			if (nx == destx && ny == desty)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;
		//否则，用新的位置继续向后走
		q.pop();
	}
	return flag;
}
//vector实现
bool Bfs(vector<vector<int>> graph, int startx, int starty, int destx, int desty)
{
	//迷宫的大小
	int m = graph.size();
	int n = graph[0].size();

	//存储迷宫中的位置
	vector<node> queue;
	queue.resize(m*n);


	//标记迷宫中的位置是否被走过
	vector<vector<int>> book;
	book.resize(m);
	for (size_t i = 0; i < m; i++)
		book[i].resize(n, 0);

	int head = 0;
	int tail = 1;
	queue[head].x = startx;
	queue[head].y = starty;
	//标记已经走过
	book[startx][starty] = 1;
	//四个行走的方向，上下左右
	int next[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	//标记是否可以出去
	bool flag = false;

	while (head < tail)
	{
		//当前位置带出所有新的位置, 可以向上下左右走
		for (size_t i = 0; i < 4; ++i)
		{
			//计算新的位置
			int nx = queue[head].x + next[i][0];
			int ny = queue[head].y + next[i][1];
			//新的位置越界，继续下一个
			if (nx >= m || nx < 0
				|| ny >= n || ny < 0)
			{
				continue;
			}
			//如果新的位置无障碍并且之前也没走过，保存新的位置
			if (graph[nx][ny] == 0 && book[nx][ny] == 0)
			{
				queue[tail].x = nx;
				queue[tail].y = ny;
				//标记已被走过
				book[nx][ny] = 1;
				++tail;
			}
			//如果新的位置为目标位置,则结束查找
			if (nx == destx && ny == desty)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;
		//否则，用新的位置继续向后走
		++head;
	}
	return flag;
}
int main()
{
	int sx, sy, ex, ey;
	vector<vector<int>> graph;
	int m, n;
	cout << "请输入迷宫的大小: 行，列" << endl;
	cin >> m >> n;
	graph.resize(m);
	for (size_t i = 0; i < m; ++i)
	{
		graph[i].resize(n);
	}
	cout << "请输入迷宫的元素" << endl;
	for (size_t i = 0; i < m; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}
	while (1)
	{
		cout << "请输入迷宫入口和出口" << endl;
		cin >> sx >> sy >> ex >> ey;
		cout << "是否可以走出迷宫： " << Bfs(graph, sx, sy, ex, ey) << endl;
	}
	return 0;
}
class Solution
{
public:
	int snakesAndLadders(vector<vector<int>> &board)
	{
		int n = board.size();
		vector<int> temp;
		for (int i = n - 1; i >= 0; i--)
		{
			if ((i + n - 1) & 1)
			{ // check if the current row is odd
				for (int j = n - 1; j >= 0; j--)
					temp.push_back(board[i][j]); // if odd, push elements in reverse order
			}
			else
			{
				for (int j = 0; j < n; j++)
					temp.push_back(board[i][j]); // if even, push elements in normal order
			}
		}
		vector<bool> vis(n * n, 0); // create a visited array
		vis[0] = 1;
		queue<int> q;
		q.push(0);
		int ct = 1; // counter to keep track of number of moves
		while (q.size())
		{
			int m = q.size();
			for (int i = 0; i < m; i++)
			{
				int x = q.front();
				for (int j = x + 1; j <= min(n * n - 1, x + 6); j++)
				{ // loop through the possible dice rolls
					int y;
					if (temp[j] == -1)
						y = j;
					else
						y = temp[j] - 1; // if the roll lands on a snake or ladder, update the index
					if (vis[y])
						continue;
					if (y == n * n - 1)
						return ct;
					vis[y] = 1;
					q.push(y);
				}
				q.pop();
			}
			ct++;
		}
		return -1;
	}
};
class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        //base case
        if(i<0 || j<0 || i>= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || grid[i][j] == 'X') return;

        grid[i][j] = 'X';

        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
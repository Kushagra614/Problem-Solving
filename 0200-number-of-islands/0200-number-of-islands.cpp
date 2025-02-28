class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        // Base case
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || grid[i][j] == 'X') {
    return;
}


        grid[i][j] = 'X';  
       
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j); 
        dfs(grid, i, j - 1); 
        dfs(grid, i, j + 1); 
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {  
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

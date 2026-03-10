class Solution {
public:

    int solveRec(int i, int j, vector<vector<int>>& dp)
    {
        //base case
        if(i == 0 && j == 0)
        {
            return 1;
        }

        if(i < 0 || j < 0)
        {
            return 0;
        }

        //store ans
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        //rec relation
        int up = solveRec(i-1, j, dp);
        int left = solveRec(i, j-1, dp);
        dp[i][j] = up + left;

        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int ans = solveRec(m-1,n-1,dp);
        return ans;
    }
};
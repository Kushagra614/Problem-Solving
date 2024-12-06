class Solution {
public:

    int solveR(vector<int>& coins, int n, int amount)
    {
        //base case
        if(amount == 0) return 1;
        if(n==0) return 0;
        

        //rec relation
        int count = 0;
        if(coins[n-1] <= amount)
        {
            count = solveR(coins,n,amount- coins[n-1]) + solveR(coins,n-1, amount);
        }
        else
        {
           count = solveR(coins, n-1, amount);
        }
        return count;
    }

    int solveDPmemo(vector<int>& coins, int n, int amount, vector<vector<int>>&dp)
    {
        //base case
        if(amount == 0) return 1;
        if(n==0) return 0;
        
        //chekc if ans exists
        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }

        //rec relation
        int count = 0;
        if(coins[n-1] <= amount)
        {
            count = solveDPmemo(coins,n,amount- coins[n-1],dp) + solveDPmemo(coins,n-1, amount,dp);
        }
        else
        {
           count = solveDPmemo(coins, n-1, amount,dp);
        }
        dp[n][amount] = count;
        return dp[n][amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1,-1));
        // return solve&dp(coins,n,amount);
        return solveDPmemo(coins,n,amount,dp);
    }
};
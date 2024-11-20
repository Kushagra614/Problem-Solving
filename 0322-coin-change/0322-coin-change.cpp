class Solution {
public:

    int solveRec(vector<int>& coins, int amount)
    {
        // base case
        if(amount == 0)
        {
            return 0;
        }

        //rec relation 
        int mini = INT_MAX;
        for(int i = 0; i<coins.size();i++)
        {
            //fidn the ans using ith coin
            int ans = 0;
            //call the rec only for valid amounts ( >= 0)
            if(amount - coins[i] >= 0)
            {
                
                ans = solveRec(coins, amount-coins[i]);
                if(ans !=INT_MAX)
                {
                int finalAns = 1 + ans;
                mini= min(mini, finalAns);
                }
                
            }
             
        }

        return mini;
    }

    // now solving using recusion + memoisation (top-down)
    int solveRec_Memo(vector<int>& coins, int amount, vector<int>&dp)
    {
        // base case
        if(amount == 0)
        {
            return 0;
        }

        //chekc if ans is present
        if(dp[amount] != -1)
        {
            return dp[amount];
        }

        //rec relation 
        int mini = INT_MAX;
        for(int i = 0; i<coins.size();i++)
        {
            //fidn the ans using ith coin
            int ans = 0;
            //call the rec only for valid amounts ( >= 0)
            if(amount - coins[i] >= 0)
            {
                
                ans = solveRec_Memo(coins, amount-coins[i],dp);
                if(ans !=INT_MAX)
                {
                int finalAns = 1 + ans;
                mini= min(mini, finalAns);
                }
                
            }
             
        }
        dp[amount] = mini;
        return dp[amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1,-1);
        int ans = solveRec_Memo(coins,amount,dp);
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
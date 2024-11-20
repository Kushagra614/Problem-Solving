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

    //now going to solve by tabulation
    /*
    STEPS:
    1) Create a dp array
    2) put initial values in the dp array
    3) now fill the dp array acc to the rec rel.

    
    */
    int solveDPtabulation(vector<int>&coins, int amount,vector<int>&dp)
    {
        // base case
        if(amount==0)
        {
            return 0;
        }


        //fill the val in dp array  
        dp[0] = 0;
        //for loop
        
        for(int k = 1; k<=amount; k++ )
        {
            int mini = INT_MAX;
            for(int i = 0; i<coins.size();i++)
        {
           
            int ans = 0;
            
            if(k - coins[i] >= 0)
            {
                
                ans = dp[k-coins[i]];
                if(ans !=INT_MAX)
                {
                int finalAns = 1 + ans;
                mini= min(mini, finalAns);
                }
                
            }
             
        }

        dp[k] = mini;
        }
        return dp[amount];

    }


    int coinChange(vector<int>& coins, int amount) {
        
        // vector<int>dp(amount+1,-1);
        vector<int>dp(amount+1,INT_MAX);
        // int ans = solveRec_Memo(coins,amount,dp);
        int ans = solveDPtabulation(coins,amount,dp);
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
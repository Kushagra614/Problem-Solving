class Solution {
public:

    int solveR(vector<int>&nums, int n, int s1)
    {
        // base case
        if(n==0) return s1 == 0? 1:0;

        //rec relation
        int count = 0;
        if(nums[n-1]<= s1)
        {
            count = solveR(nums,n-1,s1-nums[n-1]) + solveR(nums,n-1,s1);
        }
        else
        {
            count = solveR(nums,n-1,s1);
        }
        return count;
    }

    //now solving using memo
    int solveDPmemo(vector<int>&nums, int n, int s1,vector<vector<int>>&dp)
    {
        // base case
        if(n==0) return s1 == 0? 1:0;

        //check if ans exists
        if(dp[n][s1] != -1)
        {
            return dp[n][s1];
        }

        //rec relation
        int count = 0;
        if(nums[n-1]<= s1)
        {
            count = solveDPmemo(nums,n-1,s1-nums[n-1],dp) + solveDPmemo(nums,n-1,s1,dp);
        }
        else
        {
            count = solveDPmemo(nums,n-1,s1,dp);
        }
        dp[n][s1] = count;
        return dp[n][s1];
    }

    int solveDPtabulation(vector<int>&nums, int n, int s1,vector<vector<int>>&dp)
    {
        //base cases
        for(int i = 0; i<= s1; i++)
        {
            dp[0][i] = (i == 0 ? 1:0);
        }

        //putting values in the dp arr
        for(int i = 1; i<=n ; i++)
        {
            for(int j = 0; j<=s1; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] =  dp[i-1][j];
                }
            }
        }

        return dp[n][s1];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tsum = 0;
        for(int i : nums)
        {
            tsum += i;
        }

        if((tsum + target) & 1 || tsum < target) return 0;

        int s1 = (tsum + target)/2;

        // return solveR(nums,n,s1);
        // If s1 is too large, return 0
         if (s1 < 0 || s1 > 10000) {  // Adjust the limit as needed
        return 0;
        }

        vector<vector<int>>dp(n+1, vector<int>(s1+1,-1));
    

        // return solveDPmemo(nums,n,s1,dp);
        return solveDPtabulation(nums,n,s1,dp);


        
    }
};
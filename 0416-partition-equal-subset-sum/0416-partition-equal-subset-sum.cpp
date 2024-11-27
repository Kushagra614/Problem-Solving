class Solution {
public:

    bool solveR(vector<int>&nums,int n, int sum)
    {
        // base case
        if(sum == 0)return true;
        if(n==0) return false;

        //rec relation
        
        
        return solveR(nums,n-1,sum-nums[n-1]) || solveR(nums, n-1, sum);
        
        
    }


    bool solveDPmemo(vector<int>&nums,int n, int sum,vector<vector<int>>&dp)
    {
        // base case
        if(sum == 0)return true;
        if(n==0 || sum < 0) return false;

        //check if ans is present
       if (dp[n][sum] != -1) {
        return dp[n][sum];
    }

        //rec relation
        
        
        dp[n][sum] =  solveDPmemo(nums,n-1,sum-nums[n-1],dp) || solveDPmemo(nums, n-1, sum,dp);
        return dp[n][sum];
        
        
    }
    bool solveDPtabulation(vector<int>&nums,int n, int sum,vector<vector<int>>&dp)
    {
        //base case
        if(n==0 || sum<0) return false;
        if(sum == 0) return true;

         //analysing the base case and filling the dp
         for(int i = 0; i<=n; i++)
         {
            dp[i][0] = 1;
         }
         for(int j = 1; j<=sum; j++)
         {
            dp[0][j] = 0;
         }

         //rec relation
         for(int i = 1; i<= n; i++)
         {
            for(int j = 1; j<= sum; j++)
            {
                if(nums[i-1] <= j ){
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
         }

         return dp[n][sum];

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
       
        for(auto i : nums)
        {
            sum+=i;

        }
        if(sum & 1) return false;


        // return solveR(nums,n,sum/2);
        vector<vector<int>>dp(n+1, vector<int>(sum+1,-1));
        // return solveDPmemo(nums, n,  sum/2, dp);
        return solveDPtabulation(nums, n,  sum/2, dp);
       
    }
};
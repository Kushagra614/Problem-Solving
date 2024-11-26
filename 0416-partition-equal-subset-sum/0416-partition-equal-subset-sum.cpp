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
        return solveDPmemo(nums, n,  sum/2, dp);
       
    }
};
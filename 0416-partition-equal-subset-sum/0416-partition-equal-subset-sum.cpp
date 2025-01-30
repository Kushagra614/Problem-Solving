class Solution {
public:

    int DPmemo(vector<int>& nums, int n, int k,vector<vector<int>>&dp)
    {
        //base case
        if(k==0) return 1;
        if(n==0) return 0;
        
        //checking ans
        if(dp[n][k] != -1)
        {
            return dp[n][k];
        }

        //rec relation
        if(nums[n-1] <= k)
        {
            dp[n][k] = DPmemo(nums, n-1, k - nums[n-1], dp)|| DPmemo(nums, n-1, k , dp);
        }
        else
        {
            dp[n][k] =  DPmemo(nums, n-1, k , dp);
        }

        return dp[n][k];
    }

    // int DPtabu(vector<int>& nums, int n, int k,vector<vector<int>>&dp)
    // {
    //     //filling initial data
        
    // }
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        
        int sum = 0;
        for(auto i : nums)
        {
            sum+= i;
        }
        int k = sum/2;
        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
        if(sum&1) return false;
        return  DPmemo(nums, n-1, k , dp); 
    }
};
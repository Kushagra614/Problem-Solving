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

    int DPtabu(vector<int>& nums, int n, int k,vector<vector<int>>&dp)
    {
        //filling initial data
        for(int i = 0; i<= n; i++)
        {
            dp[i][0] = 1;
        }
        for(int j = 1; j<= k; j++)
        {
            dp[0][j] = 0;
        }

        //rec relation
        for(int i = 1; i<= n; i++)
        {
            for (int j = 1; j<= k; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] =  dp[i-1][j];
                }
            }
        }

        return dp[n][k];

    }
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
        return DPtabu(nums, n-1, k , dp);
        // return  DPmemo(nums, n-1, k , dp); 
        
    }
};
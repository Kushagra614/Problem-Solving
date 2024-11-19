class Solution {
public:

// now to onvert this rec into top down apporad
//1) create dp arrray
//2) rev relation and store data
//3) check if the ans is stored

    // int solveRec(vector<int>nums, int i)
    // {
    //     // basd case
    //     if(i>=nums.size())
    //     {
    //         return 0;
    //     }

    //     //Rec-Relation
    //     int include = nums[i] + solveRec(nums,i+2);
    //     int exclude = 0 + solveRec(nums,i+1);
    //     int ans = max(include, exclude);

    //     return ans;
    // }


    int solveDPtopDown(vector<int>nums, int i, vector<int>&dp)
    {
        // base case
        if(i>=nums.size())
        {
            return 0;
        }

        //step3
        if(dp[i] != -1)
        {
            return dp[i];
        }

        //Rec-Relation - step2
        int include = nums[i] + solveDPtopDown(nums,i+2,dp);
        int exclude = 0 + solveDPtopDown(nums,i+1,dp);
        dp[i] = max(include, exclude);

        return dp[i];
    }
    int rob(vector<int>& nums) {
        int i = 0;
        // return solveRec(nums,i);

        //step1
        int n = nums.size();
        vector<int>dp(n+1,-1);

        return solveDPtopDown(nums,i,dp);

    }
};
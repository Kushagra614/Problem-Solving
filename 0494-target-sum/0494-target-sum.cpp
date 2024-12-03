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
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tsum = 0;
        for(int i : nums)
        {
            tsum += i;
        }

        if((tsum + target) & 1 || tsum < target) return 0;

        int s1 = (tsum + target)/2;

        return solveR(nums,n,s1);


        
    }
};
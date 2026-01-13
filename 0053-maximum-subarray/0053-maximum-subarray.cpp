class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // int maxSum = INT_MIN;
        // int currSum = 0;
        // for(int i = 0; i < n; i++)
        // {
        //     currSum += nums[i];
        //     if(currSum > maxSum) maxSum = currSum;
        //     if(currSum < 0) currSum = 0;
            
        // }
        // return maxSum;

        int best_end = nums[0];
        int ans = nums[0];
        for(int i = 1; i < n; i++)
        {
            int n1 = best_end + nums[i];
            int n2 = nums[i];
            best_end = max(n1,n2);
            ans = max(best_end, ans);
        }
        return ans;

    }
};
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int maxSum = INT_MIN;
        // int currS = 0;
        // int curr2S = 0;
        // int n = nums.size();
        
        
        // for (int i = 0; i < n; i++) {
        //     currS += nums[(i+1) % n];
        //     if (currS > maxSum) maxSum = currS;
        //     if (currS < 0) currS = 0;
        // }
        
        // return maxSum;
        // -----------x-------------x--------------x--------------x-------------------x-----------------x


        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for (int num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            total += num;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    
    }
};
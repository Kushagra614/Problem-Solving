class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //store size
        int n = nums.size();
        //dec variables
        int sum = 0;
        int maxSum = INT_MIN;
        //iteration
        for(int i = 0; i < n ; i++)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0)
            {
                //reset
                sum = 0;
            }
            
        }
        return maxSum;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for(auto i : nums)
        {
            sum += i;
            if(sum > maxSum)
            {
                maxSum = sum;
            }

            if(sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxend = nums[0];
        int minend = nums[0];
        int ans = abs(nums[0]);

        for(int i = 1; i < n; i++)
        {
            maxend = max(maxend + nums[i], nums[i]);
            minend = min(minend + nums[i], nums[i]);
            ans = max(ans, max(abs(maxend), abs(minend)));
        }
        return ans;
    }
};
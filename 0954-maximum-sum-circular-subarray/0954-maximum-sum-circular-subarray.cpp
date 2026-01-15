class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int minend = nums[0];
        int minsum = nums[0];
        int maxend = nums[0];
        int maxsum = nums[0];

        int total = nums[0];

        for (int i = 1; i < n; i++) {
            total += nums[i];

            minend = min(nums[i], minend + nums[i]);
            minsum = min(minsum, minend);

            maxend = max(nums[i], maxend + nums[i]);
            maxsum = max(maxsum, maxend);
        }

        // guard: all elements negative
        if (maxsum < 0) return maxsum;

        return max(maxsum, total - minsum);
    }
};

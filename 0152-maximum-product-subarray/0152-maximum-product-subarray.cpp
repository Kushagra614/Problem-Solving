class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int pre = 1, suff = 1;
        int maxPro = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;

            pre *= nums[i];
            suff *= nums[n - i - 1];

            maxPro = max(maxPro, max(pre, suff));
        }

        return maxPro;
    }
};
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        //sliding window
        int ans = 0;
        int i = 0;
        int j = 0;
        int prod = 1;

        while(j<nums.size())
        {
            prod*= nums[j];

            while(prod >= k)
            {
                prod /= nums[i];
                i++;
            }

            ans += j-i+1;
            j++;
        }
    return ans;
        
    }
};
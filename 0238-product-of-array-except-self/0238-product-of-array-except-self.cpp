class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int pre = 1;
        int suff = 1;

        for(int i = 1; i < n; i++)
        {
            ans[i] *= pre * nums[i-1];
            pre *= nums[i-1];
        }

        for(int i = n-1; i >=0 ; i--)
        {
            ans[i] *= suff;
            suff *= nums[i];
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int>ppro(n,1);
    vector<int>spro(n,1);
    vector<int>ans(n,1);

    for(int i = 1; i< n; i++)
    {
        ppro[i] = ppro[i-1] * nums[i-1];
    }

    for(int i = n-2; i>= 0; i--)
    {
        spro[i] = spro[i+1] * nums[i+1];
    }

    for(int i = 0; i< n; i++)
    {
        ans[i] = ppro[i] * spro[i];
    }
    return ans;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxend = nums[0];
        int ans = nums[0];
        int minend = nums[0];
        

        for(int i = 1; i < n; i++)
        {
            int n1 = maxend * nums[i];
            int n2 = nums[i];
            int n3 = minend * nums[i];
            maxend = max(n1, max(n2,n3));
            minend = min(n1, min(n2,n3));
            ans = max(ans, max(maxend, minend));
        }



        return ans;
    }
};
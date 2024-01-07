class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int index =0; index < n; index ++){
            sum = sum + nums[index];

        }
        int totalSum = ((n)*(n+1))/2;
        int ans = totalSum - sum;
        return ans;
    }
};

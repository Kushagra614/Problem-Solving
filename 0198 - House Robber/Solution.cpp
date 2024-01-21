class Solution {
public:

    int Solve(vector<int>& nums,int n, int i){
        //base case
        if(i>=n){
            return 0;
        }

        int option1 = nums[i] + Solve(nums, n, i+2);
        int option2 = 0 + Solve(nums, n, i+1);

        int ans = max(option1, option2);
        return ans;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int finalans = Solve(nums,n,i);
        return finalans;

    }
    
};

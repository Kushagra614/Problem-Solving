class Solution {
public:
    bool canJump(vector<int>& nums) {
        int f = 0;
        int n = nums.size();

        for(int i = 0; i<n ;i++)
        {
            if(i>f)
            {
                return false;
            }
            f = max(f,nums[i]+i);
            if(f >= n-1){
                return true;
            }
        }
        return false;
    }
};
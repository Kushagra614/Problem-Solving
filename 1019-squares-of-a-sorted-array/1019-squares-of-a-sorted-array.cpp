class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        for(int i = 0; i<nums.size(); i++)
        {
            nums[i] = nums[i]*nums[i];
        }

        //now sorting using two pointers
        sort(nums.begin(), nums.end());
        return nums;


    }
};
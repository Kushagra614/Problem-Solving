class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 2;
        int j = 2;

        if(nums.size()<2) return nums.size();

        while(j<nums.size())
        {
            if( nums[j] != nums[i-2] )
            {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};
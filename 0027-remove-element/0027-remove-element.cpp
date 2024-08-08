class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        vector<int> nums1;

        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums1.push_back(nums[i]);
            }
        }

        
        nums.clear();
        nums = nums1;

        return nums.size();
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
    if(n == 0) return -1;

    int l = 0;
    int h = n - 1;
    int minval = INT_MAX;

    while(l <= h)
    {
        int mid = (l + h) / 2;

        // left part sorted
        if(nums[l] <= nums[mid])
        {
            minval = min(minval, nums[l]);
            l = mid + 1;
        }
        else
        {
            minval = min(minval, nums[mid]);
            h = mid - 1;
        }
    }

    return minval;
    }
};
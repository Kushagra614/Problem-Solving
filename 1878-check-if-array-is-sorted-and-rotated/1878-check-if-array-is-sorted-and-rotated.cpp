class Solution {
public:
    
        bool check(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return true;
    int breakCount = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            breakCount++;
        }
    }

    // Check if there is more than one break
    if (breakCount > 1) return false;

    // If there is no or exactly one break, it's a sorted rotated array
    return true;
}

    
};
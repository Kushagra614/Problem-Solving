class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int l = 0;        // Left pointer
        int r = 0;        // Right pointer
        int maxlen = 0;   // Stores the maximum length of subarray
        int zeros = 0;    // Count of zeros in the current window

        while (r < n) {
            if (nums[r] == 0) {
                zeros++;  // Increment zeros if nums[r] is zero
            }

            // If there are more than k zeros, shrink the window from the left
            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;  // Decrement zeros if nums[l] is zero
                }
                l++;  // Move the left pointer forward
            }

            // Update the maximum length of the subarray
            maxlen = max(maxlen, r - l + 1);

            r++;  // Move the right pointer forward
        }

        return maxlen;
    }
};

class Solution {
public:
    int Solve(vector<int>& nums, int n, int i) {
        // Base case
        if (i >= n) {
            return 0; // Return 0 when there are no more houses to consider
        }

        int option1 = nums[i] + Solve(nums, n, i + 2); // Rob the current house and skip the next
        int option2 = Solve(nums, n, i + 1); // Skip the current house
        int ans = max(option1, option2);
        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0]; // Only one house, so can only rob that house
        }
        int option1 = Solve(nums, n - 1, 0); // Rob houses from index 0 to n-2 (skip the last house)
        int option2 = Solve(nums, n, 1); // Rob houses from index 1 to n-1 (skip the first house)
        int finalans = max(option1, option2); // Return the maximum of the two subproblem results
        return finalans;
    }
};

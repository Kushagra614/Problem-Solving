class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Outer loop for the first number
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Two pointers technique
            int j = i + 1; // Second pointer
            int k = n - 1; // Third pointer

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    // If sum is zero, we found a triplet
                    v.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicates for the second number
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    // Skip duplicates for the third number
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    // Move both pointers inward
                    j++;
                    k--;
                }
                else if (sum < 0) {
                    // Move the second pointer to the right to increase the sum
                    j++;
                } else {
                    // Move the third pointer to the left to decrease the sum
                    k--;
                }
            }
        }
        
        return v;
    }
};

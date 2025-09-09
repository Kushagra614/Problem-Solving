class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int currentProduct = 1;
            for (int j = i; j < n; j++) {
                currentProduct *= nums[j];
                if (currentProduct > maxProduct) {
                    maxProduct = currentProduct;
                }
            }
        }

        return maxProduct;
    }
};
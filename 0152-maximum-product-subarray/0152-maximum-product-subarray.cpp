class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // ------------BRUTE FORCE-------------------------------
        // int maxProduct = INT_MIN;
        // int n = nums.size();

        // for (int i = 0; i < n; i++) {
        //     int currentProduct = 1;
        //     for (int j = i; j < n; j++) {
        //         currentProduct *= nums[j];
        //         if (currentProduct > maxProduct) {
        //             maxProduct = currentProduct;
        //         }
        //     }
        // }

        // return maxProduct;


        // ------------------OPTIMIZED APPROACH----------------------
        int maxPro = INT_MIN;
        int pre = 1, suff = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
            pre*=nums[i];
            suff*=nums[n-i-1];
            maxPro = max(maxPro, max(pre,suff));
        }
         return maxPro;
    }
};
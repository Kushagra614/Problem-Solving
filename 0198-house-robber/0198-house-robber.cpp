class Solution {
public:

// now to onvert this rec into top down apporad
//1) create dp arrray
//2) rev relation and store data
//3) check if the ans is stored

    // int solveRec(vector<int>nums, int i)
    // {
    //     // basd case
    //     if(i>=nums.size())
    //     {
    //         return 0;
    //     }

    //     //Rec-Relation
    //     int include = nums[i] + solveRec(nums,i+2);
    //     int exclude = 0 + solveRec(nums,i+1);
    //     int ans = max(include, exclude);

    //     return ans;
    // }


    int solveDPtopDown(vector<int>nums, int i, vector<int>&dp)
    {
        // base case
        if(i>=nums.size())
        {
            return 0;
        }

        //step3
        if(dp[i] != -1)
        {
            return dp[i];
        }

        //Rec-Relation - step2
        int include = nums[i] + solveDPtopDown(nums,i+2,dp);
        int exclude = 0 + solveDPtopDown(nums,i+1,dp);
        dp[i] = max(include, exclude);

        return dp[i];
    }
/*STeps for Tabluation
1) create a dp arr
2) analyise the base case and add initial values in array
3) fill the reamaing data acc to the recursive relation
*/
    int solveDPtabulation(vector<int>& nums, int i, vector<int>& dp) {
    int n = nums.size();
    if (n == 0) return 0;       // Handle empty input
    if (n == 1) return nums[0]; // Handle single element case

    // Step 2: Base cases
    dp[n - 1] = nums[n - 1]; // If we rob the last house
    for (int k = n - 2; k >= 0; --k) {
        int temp = 0;
        if (k + 2 < n) { // Handle out-of-bounds for dp[k + 2]
            temp = dp[k + 2];
        }

        int include = nums[k] + temp;
        int exclude = 0 + dp[k + 1];
        dp[k] = max(include, exclude);
    }

    // Step 3: The answer is stored at dp[0]
    return dp[0];
}

int rob(vector<int>& nums) {
    int i = 0;
    int n = nums.size();
    vector<int> dp(n, -1); // Step 1: Initialize dp with -1
    return solveDPtabulation(nums, i, dp);
}
};

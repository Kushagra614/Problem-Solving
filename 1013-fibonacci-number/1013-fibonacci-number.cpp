class Solution {
public:
    //USING RECURSION
    int fiboRec(int n)
    {
        //base case
        if(n ==0 || n == 1)
        {
            return n;
        }

        //recursive relation
        int ans = fiboRec(n-1) + fiboRec(n-2);
        return ans;
    }

    // USING DP - TOP DOWN (RECURSION + MEMEOISATION)
    int fiboDP(int n, vector<int>&dp)
    {
        //base case
        if(n==0||n==1)
        {
            return n;
        }

        //step 3: if ans already exists -> then return
        if(dp[n] != -1)
        {
            return dp[n];
        }

        //step 2: store or return ans in dp
        dp[n] = fiboDP(n-1, dp) + fiboDP(n-2, dp);
        return dp[n];
    }


    int fib(int n) {
        // int ans = fiboRec(n);
        // return ans;

        // Step 1 : Create DP array to store the ans
        vector<int>dp(n+1,-1);


        int ans = fiboDP(n,dp);
        return ans;
    }
};
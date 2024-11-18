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
    int fiboMemoDP(int n, vector<int>&dp)
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
        dp[n] = fiboMemoDP(n-1, dp) + fiboMemoDP(n-2, dp);
        return dp[n];
    }

    // USING DP - BOTTOM UP (TABULATION METHOD)
    int fiboTabDP(int n , vector<int>dp)
    {
        // base case
        if(n==0 || n==1)
        {
            return n;
        }

        //step2: Fill initial data -> byanalyzing the base case
        dp[0] = 0;
        dp[1] = 1;


        //step 3: Fill the remainaing DP -> using the logic of Rec. Relation
        //now a loop for iteration of n
        for(int i = 2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int fib(int n) {
        // int ans = fiboRec(n);
        // return ans;

        // Step 1 : Create DP array to store the ans
        vector<int>dp(n+1,-1);


        // int ans = fiboMemoDP(n,dp);
        int ans = fiboTabDP(n, dp);
        return ans;
    }
};
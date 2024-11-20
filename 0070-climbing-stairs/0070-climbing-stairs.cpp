class Solution {
public:

    // int solveRec(int n)
    // {
    //     // base case
    //     if(n==0)
    //     {
    //         return 1;
    //     }

    //     // int count = 0;
    //     //rec relation

    //     if(n>=0)
    //     {
    //     int one =  solveRec(n-1);
    //     int two =  solveRec(n-2);
    //     count = one + two;
    //     }

    //     return count;

    // }



    int solveDPmemo(int n, vector<int>&dp)
    {
        // base case
        if (n == 0 || n == 1) {
        return 1;
    }

        //setp 3: check if an is stored
        if(dp[n] != INT_MAX)
        {
            return dp[n];
        }


        int count = 0;
        //rec relation

        if(n>=0)
        {
        int one =  solveDPmemo(n-1,dp);
        int two =  solveDPmemo(n-2,dp);


        //step 2 : store the ans
        dp[n] = one + two;

        }

        return dp[n];

    }
    // Now using Tabulation Method
    int solveDPtabulation(int n,vector<int>&dp)
    {
         // base case
        if (n == 0 || n == 1) {
        return 1;
    }

        //step2: store inintal val in the array
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i<n+1 ; i++)
        {

        if(n>=0)
        {
        int one =  dp[i-1];
        int two =  dp[i-2];


        //step 2 : store the ans
        dp[i] = one + two;
        }

        }

        return dp[n];

    }

    int climbStairs(int n) {
        

        //step1: creating dp array
        vector<int>dp(n+1,INT_MAX);
        // int ans = solveRec(n);
        // int ans = solveDPmemo(n,dp);
        int ans = solveDPtabulation(n,dp);
        return ans;

    }
};
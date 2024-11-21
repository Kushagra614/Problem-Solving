class Solution {
public:


    int solveRec(vector<int>& cost,int i)
    {
        // base case
        if(i>=cost.size())
        {
            return 0;
        }

        //rec relation
        // int i = 0;
        int mini = INT_MAX;
        int ans1 = cost[i] + solveRec(cost,i+1);
        int ans2 = cost[i] + solveRec(cost,i+2);
         mini = min(ans1, ans2);

        return mini;

    }


    int solveDPmemo(vector<int>& cost,int i, vector<int>&dp)
    {
        // base case
        if(i>=cost.size())
        {
            return 0;
        }


        //chekc for ans
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        //rec relation
        // int i = 0;
        int mini = INT_MAX;
        int ans1 = cost[i] + solveDPmemo(cost,i+1,dp);
        int ans2 = cost[i] + solveDPmemo(cost,i+2,dp);

        //storing the ans;
         dp[i] = min(ans1, ans2);

        return dp[i];

    }
    int minCostClimbingStairs(vector<int>& cost) {
    
        
        // return min(solveRec(cost,1), solveRec(cost,0));

        //dp array
        vector<int>dp(cost.size(), -1);
        return min(solveDPmemo(cost,0,dp),solveDPmemo(cost,1,dp));
    }
      
};
class Solution {
public:
    int solveRec(string text1, string text2, int i, int j)
    {
        // base case
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }

        //rec relation
        //ans for match
        int ans;
        if(text1[i]==text2[j])
        {
        ans = 1 + solveRec( text1, text2, i+1, j+1);
        }
        else{
        ans =0+ max(solveRec(text1, text2, i+1, j), solveRec(text1, text2, i, j+1));

        }
        return ans;


    } 


    int solveDPmemo(string &text1, string &text2, int i, int j,vector<vector<int>>&dp)
    {
        // base case
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }
        //check for ans
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //rec relation
        //ans for match
        int ans;
        if(text1[i]==text2[j])
        {
        ans = 1 + solveDPmemo( text1, text2, i+1, j+1,dp);
        }
        else{
        ans = 0+ max(solveDPmemo(text1, text2, i+1, j,dp), solveDPmemo(text1, text2, i, j+1,dp));

        }
        dp[i][j] = ans;
        return dp[i][j];


    } 
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;

        // return solveRec(text1, text2, i, j);

        //create dp aray 
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1, -1));
        return solveDPmemo( text1, text2, i, j,dp);
    }
};
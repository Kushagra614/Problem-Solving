class Solution {
public:
    
    int solveR(string& text1, string& text2, int n, int m)
    {
        //base case
        if(n==0 || m==0)
        {
            return 0;
        }
        
        //rec relation
        if(text1[n-1]==text2[m-1])
        {
            return 1 + solveR(text1,text2,n-1,m-1); 
        }
        
        else
        {
            return max(solveR(text1,text2,n,m-1), solveR(text1,text2,n-1,m));
        }
        
        
    }
    
    int solveDPmemo(string& text1, string& text2, int n, int m, vector<vector<int>>&dp)
    {
        //base case
        if(n==0 || m==0)
        {
            return 0;
        }
        
        //check if ans is present
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
        
        int count;
        //rec relation
        if(text1[n-1]==text2[m-1])
        {
            count =  1 + solveDPmemo(text1,text2,n-1,m-1,dp); 
            return count;
        }
        
        else
        {
            count =  max(solveDPmemo(text1,text2,n,m-1,dp), solveDPmemo(text1,text2,n-1,m,dp));
            return count;
        }
        
        dp[n][m] = count;
        return dp[n][m];
    }
    
    int solveDPtabu(string& text1, string& text2, int n, int m, vector<vector<int>>&dp)
    {
        for(int i = 0; i<= n; i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 0; j<= m; j++)
        {
            dp[0][j] = 0;
        }
        
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j<= m; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] =   1 + dp[i-1][j-1];              
                    
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        // return solveR(s1,s2,n,m);
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        // return solveDPmemo(s1,s2,n,m,dp);
        return solveDPtabu(text1,text2,n,m,dp);
    }
};
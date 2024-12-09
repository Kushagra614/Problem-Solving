//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
  
    int solveR(string& s1, string& s2, int n, int m)
    {
        //base case
        if(n==0 || m==0)
        {
            return 0;
        }
        
        //rec relation
        if(s1[n-1]==s2[m-1])
        {
            return 1 + solveR(s1,s2,n-1,m-1); 
        }
        
        else
        {
            return max(solveR(s1,s2,n,m-1), solveR(s1,s2,n-1,m));
        }
        
        
    }
    
    int solveDPmemo(string& s1, string& s2, int n, int m, vector<vector<int>>&dp)
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
        if(s1[n-1]==s2[m-1])
        {
            count =  1 + solveDPmemo(s1,s2,n-1,m-1,dp); 
            return count;
        }
        
        else
        {
            count =  max(solveDPmemo(s1,s2,n,m-1,dp), solveDPmemo(s1,s2,n-1,m,dp));
            return count;
        }
        
        dp[n][m] = count;
        return dp[n][m];
    }
    
    int solveDPtabu(string& s1, string& s2, int n, int m, vector<vector<int>>&dp)
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
                if(s1[i-1] == s2[j-1])
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
    
    int getLCSLength(string& s1, string& s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        // return solveR(s1,s2,n,m);
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        // return solveDPmemo(s1,s2,n,m,dp);
        return solveDPtabu(s1,s2,n,m,dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.getLCSLength(s1, s2) << endl; // Call the getLCSLength function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
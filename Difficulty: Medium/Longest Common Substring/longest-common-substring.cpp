//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solveR(string& s1, string& s2, int n, int m, int count)
    {
        //base case
        if(n==0 || m==0)
        {
            return count;
        }
        
        //rec relation
        
        if(s1[n-1]==s2[m-1])
        {
            count =  solveR(s1,s2,n-1,m-1,count+1); 
            
        }
        
        else
        {
            count = max(count,max(solveR(s1,s2,n-1,m,0),solveR(s1,s2,n,m-1,0)));
        }
        
        return count;
        
        
        
    }
    
    int solveDPmemo(string& s1, string& s2, int n, int m, vector<vector<int>>& dp) {
        // Base case: if either string is exhausted, return 0
        if (n == 0 || m == 0) {
            return 0;
        }

        // If the result is already computed, return the stored value
        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        // If characters match, we extend the common substring length
        if (s1[n-1] == s2[m-1]) {
            dp[n][m] = 1 + solveDPmemo(s1, s2, n-1, m-1, dp);
        } else {
            dp[n][m] = 0; // Reset the value if characters do not match
        }

        return dp[n][m];
    }

    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        // Create a DP table initialized to -1
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int maxLength = 0;

        // Start checking the longest common substring from each point
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int result = solveDPmemo(s1, s2, i, j, dp);
                maxLength = max(maxLength, result);
            }
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
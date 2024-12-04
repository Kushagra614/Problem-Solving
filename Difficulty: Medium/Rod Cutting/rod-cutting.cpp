//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int solveR(vector<int> &price, int n, int currl)
    {
        //base case
        if(n==0 || currl == 0) return 0;
        
        // rec relation
        int include =0;
        int exclude = 0;
        
        if(currl <= n){
        
        include = price[currl - 1] + solveR(price, n - currl , currl);
        
        }
        
        exclude = solveR(price, n , currl-1);
        
        return max(include,exclude);
    }
    
    int solveDPmemo(vector<int>&price, int n, int currl, vector<int>&dp)
    {
        //base case
        if(n==0 || currl == 0) return 0;
        
        //checking if ans exists
        if(dp[n] != -1)
        {
            return dp[n]; 
        }
        
        //rec relation
        int include = 0;
        int exclude = 0;
        
        if(currl <= n)
        {
            include = price[currl-1] + solveDPmemo(price, n - currl, currl,dp);
            
        }
        
            exclude = solveDPmemo(price, n , currl-1, dp);
            
        dp[n] = max(include,exclude);
        return dp[n];
    }
    
    int cutRod(vector<int> &price) {
        int n = price.size();
        int currl = n;
        vector<int>dp(n+1,-1);
        return solveDPmemo(price,n,currl,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solveR(vector<int>&coins, int n, int sum)
    {
        //base case
        if(n==0) return 0;
        if(sum==0) return 1;
        
        
        
        //rec relation
        
        if(coins[n-1]<= sum)
        {
            return solveR(coins, n, sum-coins[n-1]) + solveR(coins,n-1,sum);
        }
        else
        {
           return solveR(coins,n-1,sum);
        }
        
    }
    
    int solveDPmemo(vector<int>&coins, int n, int sum, vector<vector<int>>&dp)
    {
        // base case
        if(sum==0) return 1;
        if(n==0) return 0;
        
        
        //check if ans exists
        if(dp[n][sum]!= -1)
        {
            return dp[n][sum];
        }
        
        //rec relation
        if(coins[n-1]<= sum)
        {
            dp[n][sum] =  solveDPmemo(coins, n, sum-coins[n-1],dp) + solveDPmemo(coins,n-1,sum,dp);
        }
        else
        {
           dp [n][sum] = solveDPmemo(coins,n-1,sum,dp);
        }
        
        return dp[n][sum];
        
    }
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        // return solveR(coins,n,sum);
        vector<vector<int>>dp(n+1, vector<int>(sum+1,-1));
        return solveDPmemo(coins,n,sum,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
  
    int solveR(vector<int>&coins, int n, int sum)
    {
        //base case
        if(n==0 || sum < 0) return INT_MAX;
        if(sum == 0) return 0;
        
        int include = solveR(coins,n,sum-coins[n-1]);
        int exclude = solveR(coins,n-1,sum);
        if(include != INT_MAX){
            include+=1;
        }
        
        return min(include,exclude);
        
        
    }
    
   int solveDPmemo(vector<int>&coins, int n, int sum, vector<vector<int>>&dp)
    {
        // base case
        if(n==0 || sum < 0) return INT_MAX;
        if(sum == 0) return 0;
        
        //check if ans exists
        if(dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        
        int include = INT_MAX;
        int exclude = INT_MAX;
        
        

            
    // Include the current coin if possible
    if (coins[n - 1] <= sum) {
        include = solveDPmemo(coins, n, sum - coins[n - 1], dp);
        if (include != INT_MAX) {
            include += 1;  // Add 1 to include this coin
        }
    }

    // Exclude the current coin
    exclude = solveDPmemo(coins, n - 1, sum, dp);
        
        
        
        dp[n][sum] = min(include,exclude);
        return dp[n][sum];
        
        
        
    }
    
    int minCoins(vector<int> &coins, int sum) {
        coins.erase(remove(coins.begin(), coins.end(), 0), coins.end());
        int n = coins.size();
        // int ans = solveR(coins,n,sum);
        vector<vector<int>>dp(n+1, vector<int>(sum+1,-1));
        int ans = solveDPmemo(coins,n,sum,dp);
        return (ans==INT_MAX) ? -1 : ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
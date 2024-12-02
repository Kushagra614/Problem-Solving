//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solveR(vector<int>&arr, int n, int s1)
    {
        //base case
        if (n == 0) return s1 == 0 ? 1 : 0;
        
        
        //rec relation
        if(arr[n-1]<=s1)
        {
            //include
            return solveR(arr,n-1,s1-arr[n-1]) + solveR(arr,n-1,s1);
        }
        else
        {
            //exclude
            return solveR(arr,n-1,s1);
        }
        
        
    }
    
    int solveDPmemo(vector<int>&arr, int n, int s1, vector<vector<int>>&dp)
    {
        // base case
        if(n==0) return s1 == 0 ? 1:0;
        
        //check if ans exists
        if(dp[n][s1] != -1)
        {
            return dp[n][s1];
        }
        
        //rec relation
        if(arr[n-1]<= s1)
        {
            dp[n][s1] = solveDPmemo(arr,n-1,s1-arr[n-1],dp) + solveDPmemo(arr,n-1,s1,dp);
        }
        else
        {
            //exclude
            dp[n][s1] =  solveDPmemo(arr,n-1,s1,dp);
        }
        
        return dp[n][s1];
        
        
    }
    
    int countPartitions(vector<int>& arr, int d) {
        int tsum = 0;
        for(int i : arr)
        {
            tsum+= i;
        }
        
        //now the case where the sol is invalid
        if((tsum+d) & 1 || d > tsum) return 0;
        
        int s1 = (tsum+d)/2;
        
        int n = arr.size();
        
        vector<vector<int>>dp(n+1, vector<int>(s1+1,-1));
        
        // return solveR(arr,n,s1);
        return solveDPmemo(arr,n,s1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool solveR(vector<int>&sum,int n, int target)
    {
        // base case
        if(target == 0) return true;
        if(n==0) return false;
        
        //rec relation
        if(sum[n-1] <= target)
        {
            return solveR(sum,n-1,target-sum[n-1]) || solveR(sum, n-1, target);
        }
        
        else
        {
            return solveR(sum, n-1, target);
        }
        
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        return solveR(arr,n,target);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
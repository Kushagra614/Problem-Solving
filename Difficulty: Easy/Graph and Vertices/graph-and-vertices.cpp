//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        // formula is 
        long long ans = 0;
        long long poww = 0;
        poww = (n*(n-1)/2);
        ans = pow(2,poww);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    long long int i = 0;
    long long int j = 0;
    deque<long long> dq; // Use deque instead of list for efficiency
    vector<long long> v;
    
    while (j < N) {
        // Add the current negative number to the deque
        if (A[j] < 0) {
            dq.push_back(j);
        }
        
        // If the window size is equal to K
        if (j - i + 1 == K) {
            // If the deque is not empty, get the first negative
            if (!dq.empty()) {
                v.push_back(A[dq.front()]);
                // Remove elements outside the current window
                if (dq.front() == i) {
                    dq.pop_front();
                }
            } else {
                v.push_back(0); // No negative in the current window
            }
            
            // Slide the window
            i++;
        }
        
        j++;
    }
    
    return v;
}

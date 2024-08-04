//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    // Function returns the second largest element
    int print2largest(std::vector<int> &arr) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int num : arr) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num < largest) {
                secondLargest = num;
            }
        }

        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    

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
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> leaderElements;
        int max_last = a[n - 1];
        leaderElements.push_back(max_last);

        for (int i = n - 2; i >= 0; i--) {
            if (max_last <= a[i]) {
                max_last = a[i];
                leaderElements.push_back(max_last);
            }
        }
        
        // Reverse the vector to maintain order of leaders.
        reverse(leaderElements.begin(), leaderElements.end());
        
        return leaderElements;
    }
};

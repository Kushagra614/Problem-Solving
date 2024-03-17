class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        
        // Approach here is :
        // we will sorth the original array 
        // then we will match it with the correct value
        //whihc will then give the missing no
    
        // Sort the given array
        sort(array.begin(), array.end());
        
        // Iterate through the sorted array and check if the current element matches the expected value
        for (int i = 0; i < n; i++) {
            if (array[i] != i+1) {
                return i+1; // If there's a mismatch, return the missing number
            }
        }
        
        // If no missing number found till n-1, then n is missing
        return n;
    


    }
};

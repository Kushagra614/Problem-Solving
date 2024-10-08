//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int j = 0;
        long sum = 0;
        long maxSum = LONG_MIN;
        
      
        
        
        
        for(int i = 0; i< N;i++)
        {
            sum += Arr[i];
            
            if((i-j)+1==K)
            {
                maxSum = max(maxSum, sum); 
                sum -= Arr[j]; 
                j++; //
                
            }
        }
        
       return maxSum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
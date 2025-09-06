class Solution {
  public:
    int minCost(vector<int>& arr) {
        //min heap
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(auto i : arr)
        {
            pq.push(i);
        }
        
        int ans = 0;
        while(pq.size() > 1)
        {
            int v1= pq.top(); pq.pop();
            int v2= pq.top(); pq.pop();
            int sum = v1 + v2;
            pq.push(sum);
            ans += sum;
            
            
        }
        return ans;
    }
};
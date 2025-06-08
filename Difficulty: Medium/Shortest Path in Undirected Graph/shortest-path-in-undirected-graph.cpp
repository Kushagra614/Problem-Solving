class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
      
    //    USING BFS
    
    vector<int>vis(adj.size(), 0);
    vector<int>parent(adj.size());
    queue<int>q;
    vector<int>ans;
    int count;
    
    vis[src] = 1;
    parent[src] = -1;
    q.push(src);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(auto i: adj[node])
        {
            if(!vis[i])
            {
                vis[i] = 1;
                parent[i] = node;
                q.push(i);
                
            }
        }
        
    }
    
    //now backtracking
    
    for(int i = 0; i < adj.size(); i++)
    {
        if(vis[i]){
        count = 0;
        int curr = i;
        while(curr != src)
        {
            curr = parent[curr];
            count++;
            
        }
        ans.push_back(count);
        }
        else{
            ans.push_back(-1);
        }
    }
    
    return ans;
    
    
    
    }
};